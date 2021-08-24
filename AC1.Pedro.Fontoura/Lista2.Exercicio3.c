#include <stdio.h>

int fibonacci(int n) {
  return n > 1 ? fibonacci(n - 1) + fibonacci(n - 2) : n;
}

int main() {
  int n;

  printf("Digite o valor de n para imprimir os n primeiros termos da série de Fibonacci: ");
  scanf("%d", &n);

  int i;
  for (i = 1; i <= n; i++) {
    printf("%d", fibonacci(i));

    if (i + 1 <= n) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  return 0;
}