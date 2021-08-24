#include <stdio.h>

int main() {
  int weekly_hours, hour_price;

  printf("Digite a quantidade de horas trabalhadas na semana: ");
  scanf("%d", &weekly_hours);

  printf("Digite o valor da hora trabalhada: ");
  scanf("%d", &hour_price);

  int salary = 0;

  if (weekly_hours <= 40) {
    salary += weekly_hours * hour_price;
  }

  if (weekly_hours > 40 && weekly_hours <= 60) {
    salary += 40 * hour_price;
    salary += (weekly_hours - 40) * (hour_price * 1.5);
  }

  if (weekly_hours > 60) {
    salary += 40 * hour_price;
    salary += 20 * (hour_price * 1.5);
    salary += (weekly_hours - 60) * (hour_price * 2);
  }

  printf("O salário semanal do trabalhador foi de: %d\n", salary);
}