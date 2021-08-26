#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void print_char_array(char array[BUFFER_SIZE])
{
  printf("[");

  for (int i = 0; array[i] != '\0'; i++)
  {
    printf("%c", array[i]);

    if (array[i + 1] != '\0')
      printf(", ");
  }

  printf("]\n");
}

void bubble_sort(char string[BUFFER_SIZE])
{
  char swap;

  for (int i = 0; string[i] != '\0'; i++)
  {
    for (int j = 0; string[j + 1] != '\0'; j++)
    {
      if (string[j] > string[j + 1])
      {
        swap = string[j];
        string[j] = string[j + 1];
        string[j + 1] = swap;
      }
    }
  }
}

void quick_sort(char string[BUFFER_SIZE], int left, int right)
{
  if (left < right)
  {
    char element = string[left];
    int i = left;

    char swap;

    for (int j = left + 1; j <= right; j++)
    {
      if (string[j] < element)
      {
        i++;

        swap = string[i];
        string[i] = string[j];
        string[j] = swap;
      }
    }

    swap = string[left];
    string[left] = string[i];
    string[i] = swap;

    quick_sort(string, left, i - 1);
    quick_sort(string, i + 1, right);
  }
}

int compare(const void *a, const void *b)
{
  return (*(char *)a - *(char *)b);
}

void c_qsort(char string[BUFFER_SIZE])
{
  qsort(string, strlen(string) - 1, sizeof(char), compare);
}

int main(void)
{
  char string_1[BUFFER_SIZE];

  char string_2[BUFFER_SIZE];

  char string_3[BUFFER_SIZE];

  printf("Digite a string: ");
  scanf(" %99[^\n]", string_1);

  strcpy(string_2, string_1);
  strcpy(string_3, string_1);

  printf("Bubble sort:\n");
  bubble_sort(string_1);
  print_char_array(string_1);
  printf("\n");

  printf("Quick sort:\n");
  quick_sort(string_2, 0, strlen(string_2) - 1);
  print_char_array(string_2);
  printf("\n");

  printf("qsort:\n");
  c_qsort(string_3);
  print_char_array(string_3);
  printf("\n");

  return 0;
}