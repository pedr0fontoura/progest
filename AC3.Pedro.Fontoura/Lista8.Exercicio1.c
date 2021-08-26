#include <stdio.h>
#include <stdlib.h>

int **create_int_matrix(int rows, int columns)
{
  int **matrix = malloc(sizeof(int *) * rows);

  for (int i = 0; i < rows; i++)
  {
    matrix[i] = (int *)malloc(sizeof(int) * columns);
  }

  return matrix;
}

void read_matrix(int **matrix, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("Digite o valor para a linha %d, coluna %d: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }
}

void free_matrix(int **matrix, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    free(matrix[i]);
  }

  free(matrix);
}

int main(void)
{
  int rows, columns;

  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &rows);

  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &columns);

  int **matrix = create_int_matrix(rows, columns);

  read_matrix(matrix, rows, columns);

  int match = 1;
  int sum = 0;

  for (int i = 0; i < rows; i++)
  {
    int current_sum = 0;

    for (int j = 0; j < columns; j++)
    {
      current_sum += matrix[i][j];
    }

    if (i == 0)
      sum = current_sum;

    if (sum != current_sum)
      match = 0;
    break;
  }

  free_matrix(matrix, rows);

  if (match)
  {
    printf("A soma de cada uma das linhas totaliza o mesmo valor para todas as linhas\n");
  }
  else
  {
    printf("A soma de cada uma das linhas NÃO totaliza o mesmo valor para todas as linhas\n");
  }

  return 0;
}