#include <stdio.h>

int main() {

  char operator;
  float number_a, number_b;

  printf("Digite o operador (+, -, / ou *): ");
  scanf("%c", &operator);

  printf("Digite o primeiro número: ");
  scanf("%f", &number_a);

  printf("Digite o segundo número: ");
  scanf("%f", &number_b);

  if (operator == '+') {
    printf("%f \n", number_a + number_b);
  } else if (operator == '-') {
    printf("%f \n", number_a - number_b);
  } else if (operator == '/') {
    printf("%f \n", number_a / number_b);
  } else if (operator == '*') {
    printf("%f \n", number_a * number_b);
  }

  return 0;
}