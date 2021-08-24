#include <stdio.h>

int main() {
  int *pti;
  int veti[]= { 10, 7, 2, 6, 3 };
  pti = veti;

  printf("a) %d\n", *pti);
  printf("b) %d\n", *(pti + 2));
  printf("c) %d\n", pti[4]);
  printf("d) %d\n", pti[1]);
  printf("e) %d\n", *(veti + 3));

  return 0;
}

/* 

  Resposta:

  A afirmativa falsa é a d), o correto seria pti[1] = 10

 */