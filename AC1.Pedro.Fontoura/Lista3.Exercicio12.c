#include <stdio.h>
#include <conio.h>

#define MAX_CHARACTERS 80

int main() {
  char array[MAX_CHARACTERS];
  int character_count = 0;

  printf("Digite uma frase de até 80 caracteres:\n");

  for (int i = 0; i < MAX_CHARACTERS; i++) {
    char input = getch();

    if (input == '\r') {
      break;
    } else {
      array[i] = input;
      character_count++;
    }
  }

  for (int i = 0; i < character_count; i++) {
    if (array[i] == ' ') {
      printf("\n");
    } else {
      printf("%c", array[i]);
    }

    if (i == character_count - 1) {
      printf("\n");
    }
  }

  return 0;
}