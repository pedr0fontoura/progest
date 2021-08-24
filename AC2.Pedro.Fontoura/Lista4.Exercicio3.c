/* 
  O que será impresso na tela pelo seguinte programa:


  RESPOSTA: 1020304050
 */

#include <stdio.h>

int main(void)
{
  int numbers[5];
  int *p;
  int n;

  p = numbers;
  *p = 10;

  p++;
  *p = 20;

  p = &numbers[2];
  *p = 30;

  p = numbers + 3;
  *p = 40;

  p = numbers;
  *(p + 4) = 50;

 for (n = 0; n < 5; n++) {
  printf("%d", numbers[n]);

  if (n != 4) {
    printf(" ");
  } else {
    printf("\n");
  }
 }
}