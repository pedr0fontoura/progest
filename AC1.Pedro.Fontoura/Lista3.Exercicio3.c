#include <stdio.h>

int main() {
  int i=5, *p;
  p = &i;
  printf("%x %d %d \n", p, *p+2, 3**p);
  return 0;
}

// A saída seria ffe 7 15