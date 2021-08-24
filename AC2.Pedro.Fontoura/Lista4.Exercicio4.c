/* 
  Implemente uma função que receba como parâmetros um vetor de números inteiros v e seu
  comprimento n, e verifique se os elementos do vetor correspondem aos termos de uma PA
  (Progressão Aritmética), isto é, se existe um número inteiro k tal que v[i]=v[0]+k*i. Caso os
  elementos do vetor correspondam aos termos de uma PA, a função deve retornar o valor
  calculado para k. Por exemplo, se for passado para essa função o vetor {2,10,18,26,34} a função
  deve retornar o valor 8. Caso o vetor não corresponda a uma PA, a função deve retornar o valor 0.
  Assuma que o vetor sempre terá pelo menos 3 elementos. Essa função deve ter o seguinte
  protótipo:
  int testa_PA(int n, int* v)
 */

#include <stdio.h>

int testa_PA(int n, int * v) {
  int arithmetic_progression_value = 0;
  
  for (int i = 0; i < n - 1; i++) {
    if (!arithmetic_progression_value) {
      arithmetic_progression_value = v[i + 1] - v[i];
    }

    if (v[i] + arithmetic_progression_value != v[i + 1]) {
      return 0;
    }
  }

  return arithmetic_progression_value;
}

int main(void) {
  int n;
  
  printf("Digite o número de elementos do vetor: ");
  scanf("%d", &n);

  int array[n];

  for (int i = 0; i < n; i++) {
    printf("Digite o %d elemento do vetor: ", i + 1);
    scanf("%d", &array[i]);
  }

  if (testa_PA(n, array)) {
    printf("Os elementos do vetor são uma PA\n");
  } else {
    printf("Os elementos do vetor NÃO são uma PA\n");
  }

  return 0;
}