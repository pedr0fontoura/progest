#include <stdio.h>

int main() {
  int n, i = 1, counter = 0, sum = 0;

  printf("Digite o valor de n para calcular a soma dos n primeiros números naturais ímpares: ");
  scanf("%d", &n);

  while (counter < n) {
    	if (i % 2 == 1) {
        sum += i;
        counter++; 
      }

      i++;
  }

  printf("%d\n", sum);

  return 0;
}