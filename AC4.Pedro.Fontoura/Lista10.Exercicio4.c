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
void remove_comentario(){
	char * nome_arquivo = inputString();
	FILE * leitura;
	FILE * escrita;
	leitura = fopen(nome_arquivo, "rt");
	escrita = fopen("novo.txt", "wt");
	char linha [121];
	while(fgets(linha,121,leitura)!=NULL){
		if(strstr(linha,"//") == NULL){
			fprintf(escrita, "%s", linha);
		}
	}
	fclose(leitura);
	fclose(escrita);
	unlink(nome_arquivo);
	rename("novo.txt", nome_arquivo);
}

int main(){
	remove_comentario();
}