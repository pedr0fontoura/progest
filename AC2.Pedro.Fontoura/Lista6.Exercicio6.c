#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vetorTam;
	printf("Escreva o número de caracteres: ");
	scanf ("%d",&vetorTam);
	int *vetor = (int *) malloc(vetorTam);

	int i;
	for(i = 0; i < vetorTam; i++)
	{
		int entradaNum = 0;
		printf("Escreva um número: ");
		scanf ("%d",&entradaNum);
		if(entradaNum < 0 || entradaNum > 9)
			entradaNum = 0;
		vetor[i] = entradaNum;
	}

	int flag = -1;
	for(i = 0; i < vetorTam; i++)
	{
		int numero = vetor[i];
		if(numero != flag)
		{
			int ocorrencia = 0;
			int j;
			for(j = i + 1; j < vetorTam; j++)
			{
				if(vetor[j] == numero)
				{
					ocorrencia++;
					vetor[j] = flag;
				}
			}
			if(ocorrencia > 0)
				printf("%d ", numero);
		}
	}
}
