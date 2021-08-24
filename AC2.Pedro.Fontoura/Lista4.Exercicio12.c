/* 
  Faça um programa que receba uma string do usuário (máx. 20 caracteres) e um caracter
  qualquer. O programa deve remover todas as ocorrências do caracter da string e mostrar o
  resultado.
 */

#include <stdio.h>

#define STRING_SIZE 20

int main(void) {
  char string[STRING_SIZE];
  char character;

  printf("Digite a string para ser sanitizada: ");
  scanf("%s", string);

  printf("Digite o char que deve ser removido: ");
  scanf(" %c", &character);

  int i = 0;

  char current_char;
  char next_char;

  do {
    current_char = string[i];
    next_char = string[i + 1];

    if (current_char == character) {
      int j = i;
      char char_removal_swap;
      
      do {
        char_removal_swap = string[j + 1];
        string[j + 1] = string[j];
        string[j] = char_removal_swap;
        j++;
      } while (char_removal_swap != '\0');
    }

    i++;
  } while (next_char != '\0');

  printf("Resultado: %s\n", string);

  return 0;
}