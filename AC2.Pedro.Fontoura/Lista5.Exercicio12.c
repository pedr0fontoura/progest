/* 
  Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
  estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
  estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1
 */

#include <stdio.h>

#define STRING_SIZE 50

int search_char(char * array, int size, char character) {
  int index = -1;

  for (int i = 0; i < size; i++) {
    if (character == array[i]) {
      index = i;
      break;
    }
  }

  return index;
}

int main(void) {
  char string[STRING_SIZE];
  
  char typed_characters[STRING_SIZE];
  int occurrences[STRING_SIZE];
  int count = 0;

  printf("Digite uma string de até 50 caracteres:\n");
  scanf(" %49[^\n]", string);

  int i = 0;
  char current_char;
  char next_char;

  do {
    current_char = string[i];
    next_char = string[i + 1];

    int typed_index = search_char(typed_characters, count, current_char);

    if (typed_index == -1) {
      typed_characters[count] = current_char;
      occurrences[count] = 1;
      count++;
    } else {
      occurrences[typed_index] += 1;
    }

    i++;
  } while (next_char != '\0');

  for (int j = 0; j < count; j++) {
    printf("'%c' = %d", typed_characters[j], occurrences[j]);

    if (j != count - 1) {
      printf(", ");
    }
  }

  printf("\n");

  return 0;
}
