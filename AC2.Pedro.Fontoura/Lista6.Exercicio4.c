#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam)
{
	int i, ocorrencias = 0;
	float maiornota = 0.0;
	for(i = 0; i < n; i++) //Calculando qual é a maior média ponderada
	{
		float testenota = ((t1[i] * p1) + (t2[i] * p2))/ p1 + p2;

		if(testenota > maiornota) //Se a média ponderada atual for maior que a maior registrada, ela se torna a nova maior.
		{
			maiornota = testenota;
			ocorrencias = 1; 		 //A ocorrência desta média ponderada volta pro início
		}
		else
		{
			if(testenota == maiornota) //Se tem mais alguém com essa mesma média ponderada, adicione uma ocorrência
			{
				ocorrencias++;
			}
		}
	}

	int *vetorPrem = (int *) malloc(ocorrencias); //Alocando um vetor do tamanho da quantidade de ocorrencias da maior média ponderada

	int indicePrem = 0;
	for(i = 0; i < n; i++)
	{
		float testenota = ((t1[i] * p1) + (t2[i] * p2))/ p1 + p2;
		if(testenota == maiornota) //Se o participante tiver a mesma nota que o maiornota, adiciona ele no vetor de premiados
		{
			vetorPrem[indicePrem] = inscr[i];
			indicePrem++;
		}
	}

	*tam = indicePrem; //Atribuindo o ponteiro tamanho para a variável indicePrem

	return &vetorPrem[0]; //Retornando o primeiro elemento do vetor de premiados
}


int main()
{
	//Criando as variáveis dos candidatos
	int inscr [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float notas1 [10] = { 4.9 , 5.1, 0.5, 8.0, 3.5, 9.0, 3.0, 7.0, 2.87, 9.0};
	float notas2 [10] = { 4.9 , 5.1, 0.5, 18.0, 3.5, 9.5, 3.0, 7.0, 2.87, 9.5};

	int tam;
	int *vetorDePremiados = premiados(10, &inscr[0], &notas1[0], 2, &notas2[0], 3, &tam);

	printf("Candidatos premiados: %d. \n", tam);
	int i;
	for ( i = 0; i < tam; i++ )
	{
      printf("O candidato <%d> foi premiado. \n", *(vetorDePremiados + i) );
    }

	return 0;
}
