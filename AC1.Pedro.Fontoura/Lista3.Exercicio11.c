#include <stdio.h>

int main() {
  
  int n;
  
  printf("Digite o número de pessoas: ");
  scanf("%d", &n);

  int age[n];
  float height[n];
  char sex[n];

  printf("Insira as informações da seguinte maneira: (idade) (altura) (sexo 'M' ou 'F')\n");

  for (int i = 0; i < n; i++) {
    printf("Insira os dados da %d° pessoa: ", i + 1);

    scanf("%d %f %c", &age[i], &height[i], &sex[i]);
  }

  int valid_female_count = 0;
  int valid_male_count = 0;

  float height_sum = 0.0;

  for (int i = 0; i < n; i++) {
    height_sum += height[i];

    if (sex[i] == 'M') {

      if (height[i] > 1.8)
        valid_male_count++;

    } else if (sex[i] == 'F') {

      if (age[i] > 20 && age[i] < 35)
        valid_female_count++;

    }
  }

  float average_height = height_sum / n;
  float height_variance = 0.0;

  for (int i = 0; i < n; i++) {
    height_variance += (height[i] - average_height) * (height[i] - average_height);
  }

  height_variance = height_variance / n;

  printf("Mulheres com idade entre 20 e 35 anos: %d\n", valid_female_count);
  printf("Homens com altura maior que 1.80m: %d\n", valid_male_count);

  printf("Variância da altura total foi de: %f\n", height_variance);

  return 0;
}