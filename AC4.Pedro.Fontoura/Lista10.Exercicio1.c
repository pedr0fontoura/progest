#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct funcionario
{
	char nome[121];
	float valor_hora;
	int horas_mes;
};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario **vet, char *arquivo)
{
	char linha[121];
	int valido = 1;
	int posicao = 0;
	FILE *fp;
	fp = fopen(arquivo, "rt");
	while (fgets(linha, 121, fp) != NULL)
	{
		if (posicao > (n - 1))
		{
			break;
		}
		if (valido % 2 != 0)
		{
			strncpy((*(vet + posicao))->nome, linha, 80);
		}
		else
		{
			char *token = strtok(linha, " ");
			(*(vet + posicao))->valor_hora = atof(token);
			token = strtok(NULL, "\n");
			(*(vet + posicao))->horas_mes = atoi(token);
			posicao++;
		}
		valido++;
	}
	fclose(fp);
}
