#include <stdio.h>

int maiores(int n, int * vet, int x) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    int current_value = *(vet + i);

    if (current_value > x) {
      count++;
    }
  }

  return count;
}

int main() {
  int array[] = { 1, 2, 3, 4, 5 };
  int n = 2;

  int higher_values_count = maiores(5, array, n);

  printf("Existem %d valores maiores que %d no vetor.\n", higher_values_count, n);

  return 0;
}