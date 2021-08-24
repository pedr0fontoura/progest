#include <stdio.h>

void option_1();
void option_2();
void option_3();
void option_4();
void option_5();
void option_6();
void option_7();
void option_8();

int main() {

  printf("--------------- c = 4.6 ---------------\n");

  option_1();

  printf("---------------------------------------\n\n");

  printf("--------------- c = 4.1 ---------------\n");
  
  option_2();
  printf("\n");
  option_3();
  printf("\n");
  option_4();
  
  printf("---------------------------------------\n\n");

  printf("---------------  c = 4  ---------------\n");
  
  option_5();
  printf("\n");
  option_6();
  printf("\n");
  option_7();
  printf("\n");
  option_8();

  printf("---------------------------------------\n\n");

  return 0;
}

void option_1() {

  float a = 3;
  float b = a / 2;
  float c = b + 3.1;

  printf("float a = %.1f\nfloat b = %.1f\nfloat c = %.1f\n", a, b, c);
}

void option_2() {

  int a = 3;
  int b = a / 2;
  float c = b + 3.1;

  printf("int a = %d\nint b = %d\nfloat c = %.1f\n", a, b, c);
}

void option_3() {

  int a = 3;
  float b = a / 2;
  float c = b + 3.1;

  printf("int a = %d\nfloat b = %.1f\nfloat c = %.1f\n", a, b, c);
}

void option_4() {

  float a = 3;
  int b = a / 2;
  float c = b + 3.1;
  
  printf("float a = %.1f\nint b = %d\nfloat c = %.1f\n", a, b, c);
}

void option_5() {

  int a = 3;
  int b = a / 2;
  int c = b + 3.1;

  printf("int a = %d\nint b = %d\nint c = %d\n", a, b, c);
}

void option_6() {

  float a = 3;
  int b = a / 2;
  int c = b + 3.1;
  
  printf("float a = %.1f\nint b = %d\nint c = %d\n", a, b, c);
}

void option_7() {

  float a = 3;
  float b = a / 2;
  int c = b + 3.1;
  
  printf("float a = %.1f\nfloat b = %.1f\nint c = %d\n", a, b, c);
}

void option_8() {

  int a = 3;
  float b = a / 2;
  int c = b + 3.1;
  
  printf("int a = %d\nfloat b = %.1f\nint c = %d\n", a, b, c);
}