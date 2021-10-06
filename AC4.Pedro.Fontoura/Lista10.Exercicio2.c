#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float busca (char* arquivo, char* matricula){
		char linha[121];
		FILE * fp;
		fp = fopen(arquivo, "rt");
		while (fgets(linha,121,fp) != NULL){
			char * token = strtok(linha, " ");
			if(strcmp(token, matricula)==0){
				token = strtok(NULL, "\n");
				return(atof(token));
			}
		}printf("ERRO");
		fclose(fp);
		return(-1.0);
}
