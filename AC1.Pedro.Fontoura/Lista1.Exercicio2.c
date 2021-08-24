#include <stdio.h>

int main() {

  int numbers[3], evens[3];
  int higher, lower, average = 0;

  int i;
  for (i = 0; i < 3; i++) {
    printf("Digite o valor do %d° inteiro: ", i + 1);
    scanf("%d", &numbers[i]);
    evens[i] = 0;
  }

  for (i = 0; i < 3; i++) {
    if (i == 0) {
      higher = numbers[i];
      lower = numbers[i];
    }

    if (numbers[i] > higher) {
      higher = numbers[i];
    }

    if (numbers[i] < lower) {
      lower = numbers[i];
    }

    if (numbers[i] % 2 == 0) {
      evens[i] = numbers[i];
    }

    average += numbers[i];
  }

  average = average / 3;

  printf("Maior: %d \n", higher);
  printf("Menor: %d \n", lower);

  printf("Pares: ");
  
  for (i = 0; i < 3; i++) {
    if (evens[i] != 0) {
      printf("%d", evens[i]);

      if (i + 1 < 3 && evens[i + 1] != 0) {
        printf(", ");
      }
    }
  }

  printf("\n");

  printf("Média: %d \n", average);

  return 0;
}