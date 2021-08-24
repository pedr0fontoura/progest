#include <stdio.h>

#define MIN_VALUE 1000
#define MAX_VALUE 9999

int main() {
  
  int i;
  for(i = MIN_VALUE; i <= MAX_VALUE; i++) {
    int a = i / 100;
    int b = i % 100;

    int c = a + b;

    int d = c * c;

    if (d == i) {
      printf("%d\n", d);
    }
  }

  return 0;
}