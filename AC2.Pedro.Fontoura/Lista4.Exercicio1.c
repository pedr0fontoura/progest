/* 
  Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os
  elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o
  10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o
  vetor Y
 */

#include <stdio.h>

#define ARRAY_SIZE 10

int main(void) {

  int array_x[ARRAY_SIZE];
  int array_y[ARRAY_SIZE];

  printf("Digite os %d valores separados por um espaço: ", ARRAY_SIZE);
  scanf(
    "%d %d %d %d %d %d %d %d %d %d",
    &array_x[0],
    &array_x[1],
    &array_x[2],
    &array_x[3],
    &array_x[4],
    &array_x[5],
    &array_x[6],
    &array_x[7],
    &array_x[8],
    &array_x[9]
  );

  for (int i = 0; i < ARRAY_SIZE; i++) {
    array_y[ARRAY_SIZE - 1 - i] = array_x[i];
  }

  printf(
    "O conteúdo do vetor y é: %d %d %d %d %d %d %d %d %d %d \n",
    array_y[0],
    array_y[1],
    array_y[2],
    array_y[3],
    array_y[4],
    array_y[5],
    array_y[6],
    array_y[7],
    array_y[8],
    array_y[9]
  );

  return 0;
}