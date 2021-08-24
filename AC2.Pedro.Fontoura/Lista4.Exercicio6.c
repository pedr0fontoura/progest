/* 
  A cadeia que representa a parte local de um endereço de e-mail Hotmail válido (aquela parte 
  que vem à esquerda do “@”) tem no máximo 64 caracteres e pode conter apenas letras (‘a’ a ‘z’) e 
  números (‘0’ a ‘9’), e os caracteres ponto (‘.’), hífen (‘-’) e sublinhado (‘_’). Quaisquer outros 
  caracteres especiais ou letras acentuadas não são permitidos. Além disso, a cadeia deve conter no 
  mínimo duas letras ou números, seu primeiro caractere tem que ser necessariamente uma letra, e 
  o caractere ponto (“.”) não pode aparecer em sequência ou ser o último da cadeia. Por exemplo, 
  “jsilva”, “t.o.n.y-99_”, “x-__7-” são strings válidas, enquanto “3marias”, “_peter”, “bia.”, “abc...z” 
  são incorretas. Escreva uma função em C que receba como parâmetros a cadeia s, representando 
  a parte local de um endereço de e-mail, e retorne 1 se a cadeia for válida de acordo com as 
  condições descritas, ou 0, se for inválida. A função deve ter o seguinte protótipo:
  int valida_mail(char *s)
 */

#include <stdio.h>

int is_letter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_number(char c) {
  return c >= '0' && c <= '9';
}

int valida_mail(char * s) {
  int is_valid = 0;

  char current_char;
  char next_char;

  int i = 0;

  do {
    current_char = s[i];
    next_char = s[i + 1];

    // First character is a letter
    if (i == 0 && !is_letter(current_char)) {
      is_valid = 0;
      break;
    }

    // Have at least 2 characters
    if (i == 1) {
      is_valid = 1;
    }

    // It's not a letter, a number or any accepted character
    if (!is_letter(current_char) && !is_number(current_char) && current_char != '.' && current_char != '-' && current_char != '_') {
      is_valid = 0;
      break;
    }

    // Dots in sequence
    if (current_char == '.' && next_char == '.') {
      is_valid = 0;
      break;
    }

    // Last character is a dot
    if (next_char == '\0' && current_char == '.') {
      is_valid = 0;
      break;
    }

    // String size is greater than maximum value
    if (i > 63) {
      is_valid = 0;
      break;
    }

    i++;
  } while (next_char != '\0');

  return is_valid;
}

int main(void) {

  char case_1[] = "0psnotanumber"; // @email.com
  char case_2[] = "a"; // @email.com
  char case_3[] = "test_with_invalid_character*"; // @email.com
  char case_4[] = "some..dots"; // @email.com
  char case_5[] = "last."; // @email.com
  char case_6[] = "test_with_a_really_really_really_really_really_big_local_part_string"; // @email.com
  char case_7[] = "valid"; // @email.com

  printf("%s: %d\n", case_1, valida_mail(case_1));
  printf("%s: %d\n", case_2, valida_mail(case_2));
  printf("%s: %d\n", case_3, valida_mail(case_3));
  printf("%s: %d\n", case_4, valida_mail(case_4));
  printf("%s: %d\n", case_5, valida_mail(case_5));
  printf("%s: %d\n", case_6, valida_mail(case_6));
  printf("%s: %d\n", case_7, valida_mail(case_7));

  return 0;
}