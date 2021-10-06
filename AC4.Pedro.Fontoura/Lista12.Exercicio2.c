#include <stdio.h>

int soma_impar(int vetor[], int n)
{
    static int soma = 0;

    int i = n - 1;

    if (n > 0)
    {
        if (vetor[i] % 2 != 0)
            soma = soma + vetor[i];

        soma_impar(vetor, i);
    }

    return soma;
}

int main()
{

    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    printf("Soma dos numeros impares: %d\n", soma_impar(vetor, n));
}