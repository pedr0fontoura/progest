#include <stdio.h>

int main() {

  int x, z;

  printf("Digite um valor para X: ");
  scanf("%d", &x);

  do {
    printf("Digite um valor para Z maior do que o valor de X: ");
    scanf("%d", &z);
  } while (x > z);

  int i = x, counter = 0, sum = 0;

  while (sum < z) {
    sum += i;
    i++;
    counter++;
  }

  printf("%d\n", counter);

  return 0;
}