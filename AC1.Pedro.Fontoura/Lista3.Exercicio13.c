#include <stdio.h>

int main(){
	int a,b,c,d;
	
  float f,g,h;
	
  char v[10];
	
  int x;
	
  int *p;
	p = &a;

	p++;

	printf("Valor do endereço apontado pelo ponteiro: %d\n", *p);
  printf("Endereço apontado pelo ponteiro: %p\n", p);

  printf("\n");

  printf("Endereço de a: %p\n", &a);
  printf("Endereço de b: %p\n", &b);
  printf("Endereço de c: %p\n", &c);
  printf("Endereço de d: %p\n", &d);
  printf("Endereço de f: %p\n", &f);
  printf("Endereço de g: %p\n", &g);
  printf("Endereço de h: %p\n", &h);

  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("Endereço de v[%d]: %p\n", i, v + i);
  }
}

/* 

  Valor do endereço apontado pelo ponteiro: 32767
  Endereço apontado pelo ponteiro: 0x7fff1d502fc4

  Endereço de a: 0x7fff1d502fc0
  Endereço de b: 0x7fff1d502fc4
  Endereço de c: 0x7fff1d502fc8
  Endereço de d: 0x7fff1d502fcc
  Endereço de f: 0x7fff1d502fd0
  Endereço de g: 0x7fff1d502fd4
  Endereço de h: 0x7fff1d502fd8

  Endereço de v[0]: 0x7fff1d502fee
  Endereço de v[1]: 0x7fff1d502fef
  Endereço de v[2]: 0x7fff1d502ff0
  Endereço de v[3]: 0x7fff1d502ff1
  Endereço de v[4]: 0x7fff1d502ff2
  Endereço de v[5]: 0x7fff1d502ff3
  Endereço de v[6]: 0x7fff1d502ff4
  Endereço de v[7]: 0x7fff1d502ff5
  Endereço de v[8]: 0x7fff1d502ff6
  Endereço de v[9]: 0x7fff1d502ff7

  O endereço do ponteiro coincide com o endereço da variável b.

 */