/* 
  Fazer um programa que receba uma string de no máximo 20 caracteres do usuário e mostre o
  conteúdo desta string de forma invertida.
 */

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 20

int main(void) {
  char string[STRING_SIZE];

  printf("Digite a string: ");
  scanf(" %19[^\n]", string);

  int count = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    count++;
  }

  printf("String invertida: ");

  for (int i = count - 1; i >= 0; i--) {
    printf("%c", string[i]);
  }

  printf("\n");

  return 0;
}