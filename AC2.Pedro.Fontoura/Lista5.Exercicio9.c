/* 
  Faça um programa onde o usuário digita 3 informações a respeito de uma pessoa: Nome,
endereço e telefone. Concatene essas três informações em uma única string.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
  char name[256];
  char address[256];
  char phone[256];

  char result[256 * 3];

  printf("Digite seu nome: ");
  scanf(" %255[^\n]", name);

  printf("Digite seu endereço: ");
  scanf(" %255[^\n]", address);

  printf("Digite seu telefone: ");
  scanf(" %255[^\n]", phone);

  strcat(result, name);
  strcat(result, address);
  strcat(result, phone);

  printf("Resultado: %s\n", result);
}