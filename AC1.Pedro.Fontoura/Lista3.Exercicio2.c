#include <stdio.h>

int main() {
  int i=3,j=5;
  int *p, *q;
  p = &i;
  q = &j;

  printf("a) %d\n", p == &i);
  printf("b) %d\n", *p - *q);
  printf("c) %d\n", **&p);
  printf("d) %d\n", 3* - *p/(*q)+7);

  return 0;
}

// Resposta:
// a) 1
// b) -2
// c) 3
// d) 6