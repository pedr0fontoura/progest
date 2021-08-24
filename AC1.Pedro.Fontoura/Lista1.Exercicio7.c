#include <stdio.h>
#include <math.h>

int main() {
  float floatA, floatB;

  printf("Digite um valor float (.1f) para ser arredondado para cima: ");
  scanf("%f", &floatA);

  printf("Digite um valor float (.1f) para ser arredondado para baixo: ");
  scanf("%f", &floatB);

  printf("Valor arredondado para cima (ceil): %.1f \n", ceil(floatA));
  printf("Valor arredondado para baixo (floor): %.1f \n", floor(floatB));

  return 0;
}