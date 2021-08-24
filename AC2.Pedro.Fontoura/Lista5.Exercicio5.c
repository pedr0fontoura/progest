/* 
  O que será impresso na tela pelo seguinte programa:
 */

#include <stdio.h>
#include <string.h>

int main(void) {
  char frase[80] = "o rato roeu a roupa do rei de roma";

  char *p;

  p = frase;

  p[2] = 'm';
  p[6] = '\0';

  printf("%s\n", frase);

  p = p + 3;

  printf("%s\n", p);
  printf("%ld\n", strlen(frase));

  return 0;
}

/* 
  OUTPUT:

  o mato
  ato
  6

 */