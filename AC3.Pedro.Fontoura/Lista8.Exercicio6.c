#include <stdio.h>
#include <stdlib.h>

#define N 8
#define EMPTY 0
#define PAWN 1
#define HORSE 2
#define TOWER 3
#define BISHOP 4
#define KING 5
#define QUEEN 6

void print_matrix(int matrix[N][N], int rows, int columns)
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

int main(void)
{
  int board[N][N] = {
      {1, 3, 0, 5, 4, 0, 2, 1},
      {1, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 6, 0},
      {1, 0, 0, 1, 1, 0, 0, 1},
      {0, 1, 0, 4, 0, 0, 1, 0},
      {0, 0, 3, 1, 0, 0, 1, 1},
      {1, 0, 6, 6, 0, 0, 1, 0},
      {1, 0, 5, 0, 1, 1, 0, 6}};

  int empty = 0, pawns = 0, horses = 0, towers = 0, bishops = 0, kings = 0, queens = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      switch (board[i][j])
      {
      case EMPTY:
        empty += 1;
        break;

      case PAWN:
        pawns += 1;
        break;

      case HORSE:
        horses += 1;
        break;

      case TOWER:
        towers += 1;
        break;

      case BISHOP:
        bishops += 1;
        break;

      case KING:
        kings += 1;
        break;

      case QUEEN:
        queens += 1;
        break;
      }
    }
  }

  print_matrix(board, N, N);

  printf("\n");

  printf("a) Peões e bispos: %d | Posições vazias: %d\n", pawns + bishops, empty);

  printf("b) Peões: %d, Cavalos: %d, Torres: %d, Bispos: %d, Reis: %d, Rainhas: %d, Vazio: %d\n", pawns, horses, towers, bishops, kings, queens, empty);

  return 0;
}