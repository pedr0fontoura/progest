#include <stdio.h>

int invert(int n) {
  int inverted = 0;
  
  while (n > 0) {
    inverted = inverted * 10;
    inverted = inverted + (n % 10);
    n = n / 10;
  }

  return inverted;
}

int main() {

  int n;

  printf("Digite um valor para retorná-lo escrito ao contrário: ");
  scanf("%d", &n);

  int invertedN = invert(n);

  printf("Resultado: %d\n", invertedN);

  return 0;
}