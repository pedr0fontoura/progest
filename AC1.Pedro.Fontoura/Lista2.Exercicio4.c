#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_UPPER_A 65
#define ASCII_UPPER_Z 90
#define ASCII_LOWER_A 97
#define ASCII_LOWER_Z 122
#define ASCII_UPPER_LOWER_DIFFERENCE 32

int main() {

  srand(time(NULL));

  int random_value = random() % ((ASCII_LOWER_Z + 1) - ASCII_LOWER_A);
  int ascii_random_letter = ASCII_LOWER_A + random_value;

  #ifdef DEBUG
    printf("[DEBUG] Letra sorteada \"%c\"\n", ascii_random_letter);
  #endif

  do {
    char input_letter;

    printf("Adivinhe a letra sorteada: ");
    scanf("%c", &input_letter);
    getchar();

    int ascii_input_letter = (int) input_letter;

    if (ascii_input_letter >= ASCII_UPPER_A && ascii_input_letter <= ASCII_UPPER_Z) {
      ascii_input_letter += ASCII_UPPER_LOWER_DIFFERENCE;
    }

    if (ascii_random_letter == ascii_input_letter) {
      printf("Você acertou ! A letra sorteada foi \"%c\"\n", ascii_random_letter);
      break;
    }

    if (ascii_random_letter > ascii_input_letter) {
      printf("A letra sorteada é maior do que a que você escolheu, tente novamente!\n");
    } else {
      printf("A letra sorteada é menor do que a que você escolheu, tente novamente!\n");
    }
  } while (1);

  return 0;
}