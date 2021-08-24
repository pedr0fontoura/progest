#include <stdio.h>
#include <stdlib.h>

int *repeticao(int *vet, int tam, int *n)
{
	int vetorTam = 1;
	int *vetor = (int *) malloc(vetorTam);
	vetor[0] = -1;
	int *temp = (int *) malloc(vetorTam);
	int flag = -1;
	int i;
	for(i = 0; i < tam; i++)
	{
		int numero = vet[i];
		if(numero != flag)
		{
			int ocorrencia = 0;
			int j;
			for(j = i + 1; j < tam; j++)
			{
				if(vet[j] == numero)
				{
					ocorrencia++;
					vet[j] = flag;
				}
			}
			if(ocorrencia > 0)
			{
				if(vetor[0] == -1)
					vetor[0] = numero;
				else
				{
					int j;
					free(temp);
					temp = (int *) malloc(vetorTam);
					for(j = 0; j < vetorTam; j++)
					{
						temp[j] = vetor[j];
					}

					free(vetor);
					vetorTam++;
					vetor = (int *) malloc(vetorTam);
					for(j = 0; j < vetorTam; j++)
					{
						if(j != vetorTam - 1)
						{
							vetor[j] = temp[j];
						}
						else
						{
							vetor[j] = numero;
						}
					}
					free(temp);
				}
			}
		}
	}
	if(vetor[0] == -1)
		vetorTam = 0;
	*n = vetorTam;
	return &vetor[0];
}

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

	int repeticaoCont = 0;
	int *repeticaoVet = repeticao(&vetor[0], vetorTam, &repeticaoCont);
	if(repeticaoCont > 0)
	{
		for(i = 0; i < repeticaoCont; i++)
		{
		    printf("%d ", *(repeticaoVet + i) );
		}
	}
}
