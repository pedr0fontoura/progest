/* 
  Faça um programa que dado 2 palavras, determine:
  a. Se as palavras são iguais;
  b. Verifique se a segunda palavra é uma sub string da primeira. Ex: casa e casamento.
 */

#include <stdio.h>

#define STRING_MAX_SIZE 256

int main(void) {
  char word_a[STRING_MAX_SIZE];
  char word_b[STRING_MAX_SIZE];

  printf("Digite a primeira palavra: ");
  scanf("%s", word_a);

  printf("Digite a segunda palavra: ");
  scanf("%s", word_b);

  int i = 0;
  int are_equal = 1;

  while (1) {
    if (word_a[i] != word_b[i]) {
      are_equal = 0;
      break;
    }

    i++;
  }

  i = 0;

  int is_substring = 0;

  do {
    int substring_found = 1;
    
    for (int j = 0; word_a[i + j] != '\0' && word_b[j] != '\0'; j++) {
      if (word_a[i + j] != word_b[j]) {
        substring_found = 0;
        break;
      }
    }

    if (substring_found) {
      is_substring = 1;
      break;
    }

    i++;
  } while (word_a[i] != '\0');

  if (are_equal) {
    printf("As palavras são iguais\n");
  } else {
    printf("As palavras NÃO são iguais\n");
  }

  if (is_substring) {
    printf("A segunda palavra é uma substring\n");
  } else {
    printf("A segunda palavra NÃO é uma substring\n");
  }

  return 0;
}