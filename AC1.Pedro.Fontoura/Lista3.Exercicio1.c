#include <stdio.h>

#define PI 3.14159265

void calc_circulo(float r, float *circunferencia, float *area) {
  *circunferencia = 2 * PI * r;
  *area = PI * (r * r);
}

int main() {
  float radius, circumference, area;

  printf("Digite o valor do raio para calcular a cicunferência e a área do círculo: ");
  scanf("%f", &radius);

  calc_circulo(radius, &circumference, &area);

  printf("Circunferência: %.2f\n", circumference);
  printf("Área: %.2f\n", area);
  
  return 0;
}