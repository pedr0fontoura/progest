/* 
  Escreva um programa em C para ler uma palavra e escrever:
  -A primeira letra da palavra.
  -A última letra da palavra.
  -O número de letras existente na palavra (não usar a função strlen())
 */

#include <stdio.h>

int main(void) {
  char first_char;
  char last_char;

  printf("Digite a string: ");

  int count = 0;
  
  char c = getchar();
  count++;

  first_char = c;

  while (c != '\n' && c != EOF) {
    last_char = c;
    
    c = getchar();
    count++;
  }

  printf("Primeiro caractere: %c\n", first_char);
  printf("Último caractere: %c\n", last_char);

  return 0;
}