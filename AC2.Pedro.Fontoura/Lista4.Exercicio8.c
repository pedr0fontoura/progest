/* 
  Inicialize um vetor de inteiros aleatoriamente e percorra o vetor usando dois ponteiros : um
  começando do início do vetor e outro do final até se encontrarem no meio. Obs : O vetor deve
  conter um número par de elementos.
 */

#include <stdio.h>

#define ARRAY_SIZE 8

int main(void) {

  int array[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

  int * i = array;
  int * j = array + ARRAY_SIZE - 1;

  while (i <= j) {
    printf("*i: %d | *j: %d\n", *i, *j);

    i++;
    j--;
  }

  return 0;
}