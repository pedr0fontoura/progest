/* 
  Camel case é a denominação em inglês para a prática de escrever, a partir de palavras 
  compostas ou frases, expressões constituídas pelo agrupamento dessas palavras com a letra inicial 
  maíuscula e as demais minúsculas, unidas sem espaços. Por exemplo, “NotaDaProva” seria o 
  correspondente em camel case à expressão “nota da prova”. Este é um padrão muito utilizado 
  para a criação de nomes de entidades em diversas linguagens de programação, como Java, Ruby e 
  Python. Escreva uma função em C que recebe uma cadeia de caracteres e a transforma em uma 
  cadeia no padrão camel case, ou seja, remove os espaços em branco e converte para maiúsculas 
  as letras iniciais de cada palavra. Por simplificação, considere que a cadeia de entrada contém 
  apenas letras minúsculas (entre ‘a’ e ‘z’ e espaços em branco. Por exemplo, se a cadeia “media da 
  turma” for passada para a função, será transformada na cadeia “MediaDaTurma”. O protótipo da 
  função é:
  void CamelCase (char *s);

  Obs.: uma outra prática é manter a primeira letra minúscula. Por exemplo: “media da turma” será 
  transformada na cadeia “mediaDaTurma”. Escolha qual a forma mais apropriada.

  char s[20];
  strcpy(s,”media da turma”);
  CamelCase(s);
 */

#include <stdio.h>
#include <string.h>

#define ASCII_LOWERCASE_DIFFERENCE 32

void CamelCase(char * s) {
  char current_char;
  char next_char;

  int i = 0;

  do {
    current_char = s[i];
    next_char = s[i + 1];

    int is_uppercase = current_char >= 'A' && current_char <= 'Z';

    if (i == 0 && is_uppercase) {
      current_char = (char)(current_char + ASCII_LOWERCASE_DIFFERENCE);
    }

    if (current_char == ' ') {
      s[i + 1] = (char)(next_char - ASCII_LOWERCASE_DIFFERENCE);
      
      int j = i;
      char ws_removal_swap;
      do {
        ws_removal_swap = s[j + 1];
        s[j + 1] = s[j];
        s[j] = ws_removal_swap;
        j++;
      } while (ws_removal_swap != '\0');
    }

    i++;
  } while (next_char != '\0');
}

int main(void) {
  char s[20];

  strcpy(s,"media da turma");

  CamelCase(s);

  printf("%s\n", s);

  return 0;
}