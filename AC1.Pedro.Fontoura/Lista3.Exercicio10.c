#include <stdio.h>

float media(int n, float *v) {
  float sum = 0.0;

  for (int i = 0; i < n; i++) {
    sum += *(v + i);
  }

  return sum / n;
}

int main() {
  float array[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

  float average = media(5, array);

  printf("A média dos valores do vetor é: %.1f\n", average);

  return 0;
}