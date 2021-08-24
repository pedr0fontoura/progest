/* 
  Faça um programa com funções para:

  a. ler 7 valores inteiros e os armazene em um vetor;

  b. listar o conteúdo do vetor com as referidas posições de armazenamento;

  c. pesquisar no vetor um valor inteiro qualquer de entrada e retornar a posição deste valor.
  Caso esse valor não esteja presente no vetor, então retornar –1;

  d. trocar valores contidos no vetor pela seguinte política: cada elemento i dentro do vetor
  será substituído pela soma de todos os (i-1) elementos mais o elemento i. Por exemplo, dado um
  vetor [1; 2; 3; 4; 5], após a aplicação da função teríamos esse vetor preenchido com os seguintes
  valores [1; 3; 6; 10; 15]. Para esta tarefa utilize um vetor auxiliar.
 */

#include <stdio.h>

#define ARRAY_SIZE 7

void read_values(int * array) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("Digite o valor do %d° elemento do vetor: ", i + 1);
    scanf("%d", &array[i]);
  }
}

void list_values(int * array) {
  printf("[");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d", array[i]);

    if (i != ARRAY_SIZE - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int search_value(int * array, int value) {
  int index = -1;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (value == array[i]) {
      index = i;
      break;
    }
  }

  return index;
}

void update_values(int * array) {
  int updated_array[ARRAY_SIZE];

  int sum = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    updated_array[i] = array[i] + sum;

    sum += array[i];
  }

  for (int j = 0; j < ARRAY_SIZE; j++) {
    array[j] = updated_array[j];
  }
}

/* 
There's no need to use an auxiliar array, but exercise requested ¯\_(ツ)_/¯

void update_values(int * array) {
  int sum = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    int tmp = array[i];
    array[i] += sum;

    sum += tmp;
  }
}
 */

int main(void) {

  int array[ARRAY_SIZE];

  read_values(array);

  printf("Vetor: ");
  list_values(array);

  update_values(array);

  printf("Vetor atualizado: ");
  list_values(array);

  return 0;
}