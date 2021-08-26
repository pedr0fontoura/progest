#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int *create_array(int n)
{
  int *pointer = malloc(sizeof(int) * n);

  int value = 0;

  for (int i = 0; i < n; i++)
  {
    pointer[i] = value;
    value += 5;
  }

  return pointer;
}

void print_array(int *array, int n)
{
  printf("[");

  for (int i = 0; i < n; i++)
  {
    printf("%d", array[i]);

    if (i != n - 1)
      printf(", ");
  }

  printf("]\n");
}

int main(void)
{
  int *int_array = create_array(ARRAY_SIZE);

  print_array(int_array, ARRAY_SIZE);

  free(int_array);

  return 0;
}