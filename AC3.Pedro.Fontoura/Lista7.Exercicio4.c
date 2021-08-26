#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 26

char *create_array()
{
  char *pointer = malloc(sizeof(char) * ARRAY_SIZE);

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    pointer[i] = (char)('a' + i);
  }

  return pointer;
}

void print_array(char *array, int n)
{
  printf("[");

  for (int i = 0; i < n; i++)
  {
    printf("%c", array[i]);

    if (i != n - 1)
      printf(", ");
  }

  printf("]\n");
}

int main(void)
{
  char *char_array = create_array();

  print_array(char_array, ARRAY_SIZE);

  free(char_array);

  return 0;
}