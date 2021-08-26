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

void sum_diagonal(int **matrix, int rows, int *result)
{
  int sum = 0;

  for (int i = 0; i < rows; i++)
  {
    sum += matrix[i][i];
  }

  *result = sum;
}

void multiply_matrix(int **matrix_a, int **matrix_b, int **result, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      result[i][j] = 0;

      for (int k = 0; k < rows; k++)
      {
        result[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
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

      if (j < columns - 1)
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

  printf("Digite o número de linhas das matrizes: ");
  scanf("%d", &rows);

  printf("Digite o número de colunas da matrizes: ");
  scanf("%d", &columns);

  int **matrix_a = create_int_matrix(rows, columns);
  int **matrix_b = create_int_matrix(rows, columns);

  int **sum = create_int_matrix(rows, columns);
  int diagonal_a, diagonal_b;
  int **multiplication = create_int_matrix(rows, columns);

  printf("Preencha os valores para a matriz A:\n");
  read_matrix(matrix_a, rows, columns);

  printf("Preencha os valores para a matriz B:\n");
  read_matrix(matrix_b, rows, columns);

  sum_matrix(matrix_a, matrix_b, sum, rows, columns);

  sum_diagonal(matrix_a, rows, &diagonal_a);
  sum_diagonal(matrix_b, rows, &diagonal_b);

  multiply_matrix(matrix_a, matrix_b, multiplication, rows, columns);

  printf("\n");

  printf("a)\n");
  print_matrix(sum, rows, columns);
  printf("\n");

  printf("b) Diagonal A: %d | Diagonal B: %d\n\n", diagonal_a, diagonal_b);

  printf("c)\n");
  print_matrix(multiplication, rows, columns);

  free_matrix(matrix_a, rows);
  free_matrix(matrix_b, rows);

  free_matrix(sum, rows);
  free_matrix(multiplication, rows);

  return 0;
}