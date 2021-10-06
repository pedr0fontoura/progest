#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float media (char* mat, char* nome_arquivo){
		char linha[121];
		FILE * fp;
		fp = fopen(nome_arquivo, "rt");
		while (fgets(linha,121,fp) != NULL){
			char * token = strtok(linha, " ");
			if(strcmp(token, mat)==0){
				float media = 0;
				token = strtok(NULL, " ");
				media += atof(token);
				token = strtok(NULL, " ");
				media += atof(token);
				token = strtok(NULL, "\n");
				media += atof(token);
				media = media/3;
				return media;
			}
		}printf("ERRO");
		fclose(fp);
		return(-1.0);
}
