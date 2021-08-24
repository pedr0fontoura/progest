/* 
  Elabore um programa que, dado 2 vetores inteiros de 20 posições, efetue as respectivas
  operações indicadas por um terceiro vetor de caracteres de 20 posições também fornecido pelo
  usuário, contendo as quatro operações aritméticas em qualquer combinação, armazenando os
  resultados num quarto vetor.
 */

#include <stdio.h>

#define ARRAY_SIZE 20

void list_values(int * array) {
  printf("[");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d", array[i]);

    if (i != ARRAY_SIZE - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main(void) {
  int operands_1[ARRAY_SIZE];

  int operands_2[ARRAY_SIZE];

  char operators[ARRAY_SIZE];

  int results[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("Digite o valor dos %d° operandos no formato (%%d %%d): ", i + 1);
    scanf("%d %d", &operands_1[i], &operands_2[i]);

    printf("Digite o operador (+ - * /): ");
    scanf(" %c", &operators[i]);
  }

  for (int j = 0; j < ARRAY_SIZE; j++) {
    switch(operators[j]) {
      case '+':
        results[j] = operands_1[j] + operands_2[j];
      break;

      case '-':
        results[j] = operands_1[j] - operands_2[j];
      break;

      case '*':
        results[j] = operands_1[j] * operands_2[j];
      break;

      case '/':
        results[j] = operands_1[j] / operands_2[j];
      break;
    }
  }

  printf("O vetor de resultados será: ");
  list_values(results);

  return 0;
}