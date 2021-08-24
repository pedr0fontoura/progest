#include <stdio.h>

#define TRUE_STRING "Sim"
#define FALSE_STRING "Não"

int are_grades_valid(float grades[3]);
float calculate_average(float grades[3]);

int main() {

  float grades[3], average;

  int is_approved = 0;
  int can_do_vs = 0;

  printf("Digite o valor das 3 notas: ");
  scanf("%f %f %f", &grades[0], &grades[1], &grades[2]);

  if (!are_grades_valid(grades)) {
    printf("Você inseriu uma nota inválida. O correto é (0 < Nota < 10)");
    return 1;
  }

  average = calculate_average(grades);
  
  is_approved = average >= 6.0;
  can_do_vs = average >= 4.0 && !is_approved;

  printf("Média: %.1f \n", average);

  if (is_approved) {
    printf("Aprovado: %s \n", TRUE_STRING);
  } else {
    printf("Aprovado: %s \n", FALSE_STRING);
  }

  if (can_do_vs) {
    printf("VS: %s \n", TRUE_STRING);
  } else {
    printf("VS: %s \n", FALSE_STRING);
  }

  return 0;
}

int are_grades_valid(float grades[3]) {
  int i, are_valid = 1;
  
  for (i = 0; i < 3; i++) {
    if (grades[i] < 0 | grades[i] > 10)
      are_valid = 0;
  }

  return are_valid;
}

float calculate_average(float grades[3]) {
  return (grades[0] + grades[1] + grades[2]) / 3;
}