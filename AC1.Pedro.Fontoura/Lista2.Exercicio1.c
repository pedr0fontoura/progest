#include <stdio.h>

#define PRIME_STRING "NÚMERO PRIMO\n"
#define NOT_PRIME_STRING "NÚMERO NÃO PRIMO\n"

int main() {
  int n, is_prime = 1;

  printf("Digite um número para verificar se é primo: ");
  scanf("%d", &n);

  if (n < 2) {
    printf(NOT_PRIME_STRING);
    return 0;
  }

  int i;
  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      is_prime = 0;
      break;
    }
  }

  if (is_prime) {
    printf(PRIME_STRING);
  } else {
    printf(NOT_PRIME_STRING);
  }

  return 0;
}