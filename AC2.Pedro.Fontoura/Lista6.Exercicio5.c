#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cifra_cesar(char* msg)
{
	int tam=strlen(msg); //recupera o tamanho da string texto
	char *msg_cifrada = (char *) malloc (tam);
	char letra;

	int i;
	for(i = 0; i < tam; i++)
	{
		if(msg[i] != ' ') //Tratando o caso de espaço na mensagem.
		{
			if(msg[i] == 'z') //Tratando os casos de X, Y, Z
			{
				msg_cifrada[i] = 'c';
			}
			else
			{
				if(msg[i] == 'y')
				{
					msg_cifrada[i] = 'b';
				}
				else
				{
					if(msg[i] == 'x')
					{
						msg_cifrada[i] = 'a';
					}
					else
					{
						msg_cifrada[i] = msg[i] + 3; //Para todos os outros casos, adicionar 3 na string para chegar na próxima string
					}
				}
			}
		}
	}

	return &msg_cifrada[0];
}

int main()
{
    char msg[6] = "zebra";
    char *msg_cifrada = cifra_cesar(&msg[0]);
    printf(msg_cifrada);
}
