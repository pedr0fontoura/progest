#include <stdio.h>

int main() {

  int pulo[] = { 1, 2, 3, 4, 5 };

  printf("a) Valor do %d° elemento\n", *(pulo + 2));
  printf("b) Valor do %d° elemento\n", *(pulo + 4));
  printf("c) Valor do %d° elemento\n", pulo + 4);
  printf("d) Valor do %d° elemento\n", pulo + 2);

  return 0;
}

/* 

  Resposta:

  Apenas a opção a), referencia o valor do 3° elemento da matriz.

 */