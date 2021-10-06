#include <stdio.h>
#include <string.h>

void gera_arquivos(){
	int j = 0;
	for(int i = 1, counter = 0;counter<10;counter++,i++){
		if(i>9){
			j++;
			i = 0;
		}
		char nome_arquivo[8];
		char dentro_arquivo[32];
		snprintf(nome_arquivo,8, "teste%d%d",j,i);
		snprintf(dentro_arquivo,32, "Texto do arquivo[%d%d]",j,i);
		FILE * fp;
		fp = fopen(nome_arquivo, "wt");
		fputs(dentro_arquivo,fp);
	}
}

int main(){
	gera_arquivos();
}