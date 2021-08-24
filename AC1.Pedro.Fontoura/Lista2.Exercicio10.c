#include <stdio.h>

int mdc (int x, int y) {
  int higher, lower, rest;

  if (x > y) {
    higher = x;
    lower = y;
  } else {
    higher = y;
    lower = x;
  }

  do {
    rest = higher % lower;
    higher = lower;
    lower = rest;
  } while (rest);

  return higher;
}

int main() {

  int x, y;

  printf("Digite os dois valores para encotrar o MDC: ");
  scanf("%d %d", &x, &y);

  int gcd = mdc(x, y);

  printf("O MDC é: %d\n", gcd);

  return 0;
}