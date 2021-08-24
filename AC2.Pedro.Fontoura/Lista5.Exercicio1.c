/* 
  Faça um programa com uma função que calcule o número de vogais existentes em uma string. A
  função recebe a string e atualiza a resposta (número de vogais) em uma variável que foi passada por
  referência.
 */

#include <stdio.h>

void count_vowels(char * string, int * value) {
  int vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

  int count = 0;

  int i = 0;
  char current_char;
  char next_char;

  do {
    current_char = string[i];
    next_char = string[i + 1];

    for (int j = 0; j < 5; j++) {
      if (current_char == vowels[j]) {
        count++;
        break;
      }
    }

    i++;
  } while (current_char != '\0');

  *value = count;
}

int main(void) {

  char string[50];
  int count;

  printf("Digite a string para contar as vogais presentes: ");
  scanf("%49[^\n]", string);

  count_vowels(string, &count);

  printf("Número de vogais: %d\n", count);

  return 0;
}