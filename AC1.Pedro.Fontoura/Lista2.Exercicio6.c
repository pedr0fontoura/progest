#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 0
#define MAX_VALUE 100

int main() {

  srand(time(NULL));

  int random_value = random() % ((MAX_VALUE + 1) - MIN_VALUE);

  #ifdef DEBUG
    printf("[DEBUG] Número sorteado: %d\n", random_value);
  #endif

  int attempts = 0;

  do {
    int input;

    printf("Adivinhe o número sorteado: ");
    scanf("%d", &input);

    attempts++;

    if (random_value == input) {
      printf("Você acertou ! O número sorteado foi: %d.\n", random_value);
      printf("Número de tentativas: %d\n", attempts);
      break;
    }

    if (random_value > input) {
      printf("O número sorteado é maior do que o que você escolheu, tente novamente!\n");
    } else {
      printf("O número sorteado é menor do que o que você escolheu, tente novamente!\n");
    }
  } while (1);

  return 0;
}