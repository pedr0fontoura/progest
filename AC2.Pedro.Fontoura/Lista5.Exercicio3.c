/* 
  Construa uma função que receba como argumento de entrada uma cadeia de 20 caracteres e um
  caractere e retorne o número de vezes que este caractere aparece na cadeia.
 */

#include <stdio.h>

#define STRING_SIZE 20

int count_char(char * string, char character) {
  int count = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == character) count++;
  }

  return count;
}

int main(void) {

  char string[STRING_SIZE];
  char character;

  printf("Digite a string: ");
  scanf("%19[^\n]", string);

  printf("Digite o caractere a ser contado: ");
  scanf(" %c", &character);

  int count = count_char(string, character);

  printf("O caractere '%c' aparece %d vezes na string\n", character, count);

  return 0;
}