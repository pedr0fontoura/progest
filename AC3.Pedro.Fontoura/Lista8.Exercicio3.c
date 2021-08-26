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

void sum_matrix(int **matrix_a, int **matrix_b, int **result, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      result[i][j] = matrix_a[i][j] + matrix_b[i][j];
    }
  }
}

void transpose_matrix(int **matrix, int **result, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      result[i][j] = matrix[j][i];
    }
  }
}

void print_matrix(int **matrix, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    printf("|");

    for (int j = 0; j < columns; j++)
    {
      printf("%d", matrix[i][j]);

      if (j < rows - 1)
      {
        printf(", ");
      }
    }

    printf("|\n");
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

  printf("Digite o número de linhas das matriz: ");
  scanf("%d", &rows);

  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &columns);

  int **matrix = create_int_matrix(rows, columns);
  int **transposed = create_int_matrix(rows, columns);

  read_matrix(matrix, rows, columns);

  transpose_matrix(matrix, transposed, rows, columns);

  printf("Matriz original:\n");
  print_matrix(matrix, rows, columns);

  printf("Matriz transposta:\n");
  print_matrix(transposed, rows, columns);

  free_matrix(matrix, rows);
  free_matrix(transposed, rows);

  return 0;
}