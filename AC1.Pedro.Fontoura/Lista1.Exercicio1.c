#include <stdio.h>

int main() {
  int n, hours, minutes, seconds;

  printf("Digite o valor inteiro de n segundos para converter em horas, minutos e segundos: ");
  scanf("%d", &n);

  hours = n / 3600;
  minutes = (n % 3600) / 60;
  seconds = (n % 3600) % 60;

  printf("%dh %dmin %ds \n", hours, minutes, seconds);

  return 0;
}