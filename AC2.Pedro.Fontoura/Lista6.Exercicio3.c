#include <stdio.h>
#include <stdlib.h>

int* aprovados (int n, int *mat, float *notas, int *tam)
{
	int i, contadorAprov = 0;
	for(i = 0; i < n; i++) //Contando a quantidade de aprovados
	{
		if(notas[i] >= 5.0)
			contadorAprov++;
	}

	int *vetorAprov = (int *) malloc(contadorAprov); //Alocando um vetor do tamanho da quantidade de aprovados previsto
	int indiceAprov = 0;
	for(i = 0; i < n; i++) //Revisitando o vetor de notas para atribuir as matrículas aprovadas para o vetor de aprovados
	{
		if(notas[i] >= 5.0)
		{
			vetorAprov[indiceAprov] = mat[i];
			indiceAprov++;
		}
	}

	*tam = contadorAprov; //Atribuindo o ponteiro tamanho para a variável contadorAprov

	return &vetorAprov[0]; //Retornando o primeiro elemento do vetor de aprovados
}


int main()
{
	//Criando as variáveis da turma
	int mat [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float notas [10] = { 4.9 , 5.1, 0.5, 8.0, 3.5, 9.0, 3.0, 7.0, 2.87, 9.0};

	int tam = 0;
	int *vetorDeAprovados = aprovados(10, &mat[0], &notas[0], &tam);


	printf("Alunos Aprovados: %d. \n", tam);
	int i;
	for ( i = 0; i < tam; i++ )
	{
      printf("Aluno <%d> foi aprovado. \n", *(vetorDeAprovados + i) );
    }

	return 0;
}
