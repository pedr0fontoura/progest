#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int distances[N][N] = {
    {0, 15, 30, 5, 12},
    {15, 0, 10, 17, 28},
    {30, 10, 0, 3, 11},
    {5, 17, 3, 0, 80},
    {12, 28, 11, 80, 0}};

void search_distances()
{
  int city_a, city_b;

  do
  {
    printf("  Digite as cidades que você deseja saber a distância:\n");

    printf("  Cidade A: ");
    scanf(" %d", &city_a);

    printf("  Cidade B: ");
    scanf(" %d", &city_b);

    if (city_a == 0 && city_b == 0)
      break;

    printf("  Distância: %d\n", distances[city_a - 1][city_b - 1]);
  } while (city_a != 0 && city_b != 0);
}

void print_matrix()
{
  for (int i = 0; i < N; i++)
  {
    printf("  |");

    for (int j = i; j < N; j++)
    {
      printf("%d", distances[i][j]);

      if (j < N - 1)
      {
        printf(", ");
      }
    }

    printf("|\n");
  }
}

void route()
{
  printf("  Digite sua rota, separando as cidades por espaço: ");
  char route_string[80];

  scanf(" %79[^\n]", route_string);

  int distance = 0;
  int city_a, city_b;

  char *token = strtok(route_string, ",");

  while (token != NULL)
  {
    city_a = atoi(token);

    token = strtok(NULL, ",");

    if (token == NULL)
      break;

    city_b = atoi(token);

    distance += distances[city_a - 1][city_b - 1];
  }

  printf("  A distância é de %d km", distance);
}

int main(void)
{
  printf("a)\n");
  search_distances();
  printf("\n");

  printf("\nb)\n");
  print_matrix();
  printf("\n");

  printf("\nc)\n");
  route();
  printf("\n");

  return 0;
}