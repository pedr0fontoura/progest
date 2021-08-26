#include <stdio.h>
#include <string.h>

int main(void)
{
  char *frase = "Otimo teste";
  char *p, misterio[80];

  int i = 0;
  int j = 0;

  p = frase + strlen(frase) - 1;
  // p = frase[10]; p aponta para a última letra da frase

  while (*p != ' ')
  {
    misterio[i] = *p;
    i++;
    p--;
  }

  // Lê a frase de traz pra frente até o primeiro espaço
  // misterio = "etset"

  misterio[i] = ' ';
  i++;

  // Adiciona um espaço
  // misterio = "etset "

  while (frase[j] != ' ')
  {
    misterio[i] = frase[j];
    j++;
    i++;
  }

  // Lê a frase normalmente até o primeiro espaço
  // misterio = "etset Otimo"

  misterio[i] = '\0';

  // Adiciona EOS no final de misterio

  puts(misterio);

  return 0;
}

/* 

OUTPUT:

estset Otimo

 */