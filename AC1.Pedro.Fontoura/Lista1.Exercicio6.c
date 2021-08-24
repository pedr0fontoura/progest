#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c;

  printf("Digite os valores de a, b, c para uma equação de 2° grau ax^2 + bx + c = 0\n");
  
  printf("Digite o valor de a: ");
  scanf("%d", &a);

  printf("Digite o valor de b: ");
  scanf("%d", &b);

  printf("Digite o valor de c: ");
  scanf("%d", &c);

  int delta, root_a, root_b;

  delta = sqrt((b * b) - (4 * a * c));
  root_a = ((b * -1) + delta) / (2 * a);
  root_b = ((b * -1) - delta) / (2 * a);

  printf("Raízes: %d, %d \n", root_a, root_b);

  return 0;
}