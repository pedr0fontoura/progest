/* 
  Faça um programa que dado um nome completo, retorne a abreviatura deste nome. Não se devem
  abreviar as preposições como: do, de, etc. A abreviatura deve vir separada por pontos. Ex: Paulo
  Jose de Almeida Prado. Abreviatura: P.J.A.P.
 */

#include <stdio.h>

#define STRING_MAX_SIZE 256

int main(void) {
  char string[STRING_MAX_SIZE];

  int count = 0;
  char abbreviations[STRING_MAX_SIZE];
  
  printf("Digite o nome a ser abreviado: ");
  scanf("%255[^\n]", string);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      abbreviations[count] = string[i];
      count++;
    }
  }

  for (int j = 0; j < count; j++) {
    printf("%c.", abbreviations[j]);
  }

  printf("\n");

  return 0;
}