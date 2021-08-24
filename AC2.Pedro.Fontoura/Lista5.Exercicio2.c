/* 
  Mostre e explique (comentando as linhas de código) o que será impresso na tela:
 */

#include <stdio.h>
#include <string.h>

int main(void) {
  // Declara string
  char texto[] = "foi muito facil";
  
  // Declara a variável `i` e a incrementa até a posição do primeiro espaço em branco na string
  int i;
  for (i = 0; texto[i] != '\0'; i++) {
    if (texto[i] == ' ') break;
  }

  // Incrementa a variável `i` para indicar a posição da primeira letra após o primeiro espaço em branco
  i++;

  // Imprime todos os caracteres subsequentes até o final da string, resultado "muito facil"
  for (; texto[i] != '\0'; i++) {
    printf("%c", texto[i]);
  }

  // Não faz parte do código original da questão, só melhora a legibilidade do output
  printf("\n");

  return 0;
}
