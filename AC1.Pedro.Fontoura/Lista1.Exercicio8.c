#include <stdio.h>

int total_bills(int value);

int main() {

  int value;
  printf("Digite um valor inteiro em R$ para encontrar o menor número de notas necessárias: R$");
  scanf("%d", &value);

  int bills = total_bills(value);

  printf("Total de notas: %d\n", bills);

  return 0;
}

int total_bills(int value) {
  int bills_100 = 0, bills_50 = 0, bills_20 = 0, bills_10 = 0, bills_5 = 0, bills_2 = 0, bills_1 = 0;

  bills_100 = value / 100;
  bills_50 = (value % 100) / 50;
  bills_20 = ((value % 100) % 50) / 20;
  bills_10 = (((value % 100) % 50) % 20) / 10;
  bills_5 = ((((value % 100) % 50) % 20) % 10) / 5;
  bills_2 = (((((value % 100) % 50) % 20) % 10) % 5) / 2;
  bills_1 = ((((((value % 100) % 50) % 20) % 10) % 5) % 2);

  printf("%d x R$ 100\n", bills_100);
  printf("%d x R$ 50\n", bills_50);
  printf("%d x R$ 20\n", bills_20);
  printf("%d x R$ 10\n", bills_10);
  printf("%d x R$ 5\n", bills_5);
  printf("%d x R$ 2\n", bills_2);
  printf("%d x R$ 1\n", bills_1);

  return bills_100 + bills_50 + bills_20 + bills_10 + bills_5 + bills_2 + bills_1;
}