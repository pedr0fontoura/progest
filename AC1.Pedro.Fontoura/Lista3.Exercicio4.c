#include <stdio.h>

int divs(int n, int *max, int *min) {
  int is_prime = 1, greatest = 0, lowest = 0;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      is_prime = 0;

      if (!lowest)
        lowest = i;

      if (i > greatest)
        greatest = i;
    }
  }

  if (!is_prime) {
    *min = lowest;
    *max = greatest;
  }

  return is_prime;
}

int main() {
  int n, is_prime, min, max;

  printf("Digite um número n para verificar se ele é primo, caso não seja, descubra o menor e o maior divisor: ");
  scanf("%d", &n);
  
  is_prime = divs(n, &max, &min);

  if (is_prime) {
    printf("O número %d é um número primo!\n", n);
  } else {
    printf("O número %d não é um número primo!\n", n);
    printf("Seu menor divisor é %d e o maior é %d.\n", min, max);
  }

  return 0;
}