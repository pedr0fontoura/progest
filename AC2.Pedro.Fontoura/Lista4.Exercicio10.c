/* 
  Um cinema que possui capacidade de 20 lugares está sempre lotado. Certo dia cada
  espectador respondeu a um questionário, onde constava:
  - sua idade;
  - sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
  Elabore um programa que, recebendo estes dados calcule e mostre:
  a. a quantidade de respostas ótimo;
  b. a diferença percentual entre respostas bom e regular;
  c. a média de idade das pessoas que responderam ruim;
  d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
  e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que
  respondeu ruim.
 */

#include <stdio.h>

#define ARRAY_SIZE 20

int main(void) {
  int ages[ARRAY_SIZE];
  int ratings[ARRAY_SIZE];

  int excellent_count = 0;
  int excellent_older_age = 0;

  int good_count = 0;

  int regular_count = 0;
  
  int bad_count = 0;
  float bad_age_average = 0;
  int bad_older_age = 0;

  int terrible_count = 0;
  int terrible_older_age = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (i != 0) {
      printf("\n-----------------------------\n\n");
    }

    int age, rating;

    printf("Digite a sua idade: ");
    scanf("%d", &age);

    printf("\nAVALIAÇÕES: 5 - ÓTIMO | 4 - BOM | 3 - REGULAR | 2 - RUIM | 1 - PÉSSIMO\n");
    printf("\nDigite o valor correspondente a sua avaliação: ");
    scanf("%d", &rating);

    switch (rating) {
      case 5:
        excellent_count += 1;

        if (age > excellent_older_age) {
          excellent_older_age = age;
        }
      break;

      case 4:
        good_count += 1;
      break;

      case 3:
        regular_count += 1;
      break;

      case 2:
        bad_count += 1;
        bad_age_average += age;

        if (age > bad_older_age) {
          bad_older_age = age;
        }
      break;

      case 1:
        terrible_count += 1;

        if (age > terrible_older_age) {
          terrible_older_age = age;
        }
      break;
    }
  }

  bad_age_average = bad_age_average / bad_count;

  int good_regular_percentage_difference = (((good_count - regular_count) * (good_count - regular_count)) * (1 / 2)) / ARRAY_SIZE * 100;

  int terrible_percentage = terrible_count / ARRAY_SIZE * 100;

  int excellent_bad_older_age_difference = ((excellent_older_age - bad_older_age) * (excellent_older_age - bad_older_age)) * (1 / 2);

  printf("a) Número de respostas ÓTIMO: %d\n", excellent_count);
  printf("b) Diferença percentual entre respostas BOM e REGULAR: %d%%\n", good_regular_percentage_difference);
  printf("c) Média de idade das pessoas que responderam RUIM: %.1f\n", bad_age_average);
  printf("d) Porcentagem de respostas PÉSSIMO: %d%%\n", terrible_percentage);
  printf("e) A diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim é: %d\n", excellent_bad_older_age_difference);

  return 0;
}