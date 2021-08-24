#include <stdio.h>
#include <math.h>

int main() {

  int a, b;

  printf("Digite o valor da base da exponênciação: ");
  scanf("%d", &a);

  printf("Digite o valor da potência: ");
  scanf("%d", &b);

  int c = pow(a, b);

  printf("Resultado: %d\n", c);

  return 0;
}