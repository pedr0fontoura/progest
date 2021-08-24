/* 
  Escreva um programa em C para ler um vetor R (de 5 elementos) e um vetor S (de 10
  elementos). Gere um vetor X que possua os elementos comuns a R e a S. Considere que pode
  existir repetição de elementos no mesmo vetor. Nesta situação somente uma ocorrência do
  elemento comum aos dois deve ser copiada para o vetor X. Após o término da cópia, escrever o
  vetor X.
 */

#include <stdio.h>

int exists(int element, int * array, int n) {
  for (int i = 0; i < n; i++) {
    if (array[i] == element) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  int array_r[5];
  int array_s[10];
  int array_x[5];

  printf("Digite os 5 valores de R separados por um espaço: ");
  scanf(
    "%d %d %d %d %d",
    &array_r[0],
    &array_r[1],
    &array_r[2],
    &array_r[3],
    &array_r[4]
  );

  printf("Digite os 10 valores de S separados por um espaço: ");
  scanf(
    "%d %d %d %d %d %d %d %d %d %d",
    &array_s[0],
    &array_s[1],
    &array_s[2],
    &array_s[3],
    &array_s[4],
    &array_s[5],
    &array_s[6],
    &array_s[7],
    &array_s[8],
    &array_s[9]
  );

  int common_elements_count = 0;

  for (int i = 0; i < 5; i++) {
    int current_element = array_r[i];

    for (int j = 0; j < 10; j++) {
      if (current_element == array_s[j] && !exists(current_element, array_x, common_elements_count)) {
        array_x[common_elements_count] = current_element;
        common_elements_count++;
      }
    }
  }

  printf("O vetor x é igual a: ");

  for (int i = 0; i < common_elements_count; i++) {
    if (i < common_elements_count - 1) {
      printf("%d ", array_x[i]);
    } else {
      printf("%d\n", array_x[i]);
    }
  }

  return 0;
}