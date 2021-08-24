/* 
  Faça um programa que demonstre o uso de 3 funções da biblioteca string.h que ainda não
  tenham sido usadas em listas de exercícios da disciplina.
 */

#include <stdio.h>
#include <string.h>

int main(void) {

  printf("-------------- string.h: STRTOK --------------\n\n");

  char string_a[] = "Laranja;Banana;Maçã";
  char *token;

  printf("String original: %s\n", string_a);
  printf("Tokens:\n\n");

  token = strtok(string_a, ";");

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ";");
  }

  printf("\n----------------------------------------------\n\n");

  printf("-------------- string.h: STRCMP --------------\n\n");

  char string_b[] = "Vermelho";
  char string_c[] = "Azul";
  char string_d[] = "Vermelho";

  if (strcmp(string_b, string_c) != 0) {
    printf("As strings '%s' e '%s' são diferentes\n", string_b, string_c);
  }

  if (strcmp(string_b, string_d) == 0) {
    printf("As strings '%s' e '%s' são iguais\n", string_b, string_d);
  }

  printf("\n----------------------------------------------\n\n");

  printf("-------------- string.h: STRERROR --------------\n\n");

  int errorcode = 1;

  printf("Error Code: %d\n", errorcode);
  printf("Error: %s\n", strerror(errorcode));

  printf("\n----------------------------------------------\n\n");

  return 0;
}