#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input()
{
  int n = 1, i = 0;

  char *buffer = malloc(sizeof(char) * n);

  while (1)
  {
    n++;

    buffer = realloc(buffer, sizeof(char) * n);

    char c;

    scanf("%c", &c);

    if (c == '\n')
      break;

    buffer[i] = c;

    i++;

    buffer[i] = '\0';
  }

  return buffer;
}

int main(void)
{

  printf("Digite os nomes:\n");

  int n = 0;
  char **names = NULL;

  while (1)
  {
    char *value = input();

    if (!strcmp(value, "fim"))
      break;

    n++;

    names = realloc(names, sizeof(char *) * n);

    names[n - 1] = value;
  }

  printf("\nNomes:\n");

  for (int i = 0; i < n; i++)
  {
    printf("[%d] %s\n", i, names[i]);

    free(names[i]);
  }

  free(names);

  return 0;
}