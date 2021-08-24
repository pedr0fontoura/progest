#include <stdio.h>

float max_vet(int n, float * vet) {
  float max = *vet;

  for (int i = 0; i < n; i++) {
    float current_value = *(vet + i);

    if (current_value > max) {
      max = current_value;
    }
  }

  return max;
}

int main() {
  float array[] = { 2.2, 1.6, 3.4, 1.5, 5.3 };

  float max = max_vet(5, array);

  printf("O maior valor no vetor é %.1f\n", max);
  
  return 0;
}