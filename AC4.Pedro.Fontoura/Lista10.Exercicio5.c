//Um numero real por linha
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * inputString(){
	printf("Digite o nome do arquivo (com extensao):\n");
	char * str;
	int ch;
	size_t len = 0;
	size_t size = 10;
	str = realloc(NULL, sizeof(*str)*size);
	while(1){
		ch = getc(stdin);
		if(ch=='\n'){
			break;
		}
		str[len++]=ch;
		if(len==size){
			str = realloc(str,sizeof(*str)*(size+=16));
		}
	}return str;
}

float media(){
	char * nome_arquivo = inputString();
	FILE * fp;
	fp = fopen(nome_arquivo, "rt");
	float * vet;
	size_t len = 0;
	size_t size = 1;
	float media = 0;
	char linha[121];
	vet = realloc(NULL,sizeof(*vet)*size);
	while(fgets(linha,121,fp)!=NULL){
		vet[len++] = atof(linha);
		media+=atof(linha);
		if(len == size){
			vet = realloc(vet, sizeof(*vet)*(size++));
		}
	}
	fclose(fp);
	return(media/(size-1));
}

int main(){
	printf("%f",media());
	while(1){}
}