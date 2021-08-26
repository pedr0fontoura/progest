#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
  char texto[MAX + 2], temp;

  int tam, i;

  // Lê o input do usuário
  gets(texto);

  // Tamanho da string digitada pelo usuário
  tam = strlen(texto);

  // Itera pela string que foi digitada pelo usuário
  for (i = 0; i < tam; i++)
  {
    // Armazena o char na posição i em uma variável temporária
    temp = texto[i];

    // Faz um swap dos valores das posições i e n - i
    texto[i] = texto[tam - 1 - i];
    texto[strlen(texto) - 1 - i] = temp;
  }

  // Imprime a string
  puts(texto);

  return 0;
}

// O output é o mesmo que o input pois o swap acontece para todos os chars, até para os que já passaram por um swap