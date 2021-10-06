#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _ALUNO {
	char nome [81];
	float nota1 , nota2;
} ALUNO;

char * inputString(){
	printf("Digite o nome do aluno:\n");
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
	}
	printf("%s\n", str);
	return str;
}

void grava_em_binario(char * nome_arquivo, int numero_alunos, ALUNO * vet){
	FILE *fp = fopen(nome_arquivo,"wb");
	fwrite(vet,sizeof(ALUNO),numero_alunos,fp);
	fclose(fp);
}

void carrega_do_binario(char * nome_arquivo, int numero_alunos, ALUNO * vet){
	FILE * fp = fopen(nome_arquivo,"rb");
	fread(vet,sizeof(ALUNO),numero_alunos,fp);
	fclose(fp);
}

void imprime_alunos_acima_da_media(char * nome_arquivo, int numero_alunos){
	ALUNO vet[numero_alunos];
	carrega_do_binario(nome_arquivo, numero_alunos, vet);
	for(int i = 0; i<numero_alunos;i++){
		if((((vet+i)->nota1 + (vet+i)->nota2)/2)>6){
			puts((vet+i)->nome);
		}
	}
}

int consulta(char * nome_arquivo, int numero_alunos){
	char * aluno = inputString();
	ALUNO vet[numero_alunos];
	carrega_do_binario(nome_arquivo,3,vet);
	for(int i = 0; i<numero_alunos;i++){
		if(strcmp((vet+i)->nome,aluno)==0){
			printf("Media: %f\n", ((vet+i)->nota1 + (vet+i)->nota2)/2);
			return 1;
		}
	}printf("Aluno nao encontrado\n");
	return 0;
}

void incluir(char * nome_arquivo,int  * num_alunos){
	ALUNO novo_aluno;
	char * str = inputString();
	strcpy(novo_aluno.nome,str);
	printf("Insira a primeira nota do aluno:\n");
	scanf("$f", &(novo_aluno.nota1));
	getc(stdin);
	printf("Insira a segunda nota do aluno:\n");
	scanf("$f", &(novo_aluno.nota2));
	FILE *fp = fopen(nome_arquivo, "ab");
	fwrite(&novo_aluno,sizeof(ALUNO),1,fp);
	* num_alunos +=1;
}

void excluir(char *nome_arquivo, int * num_alunos){
	FILE * leitura;
	FILE * escrita;
	char * nome = inputString();
	ALUNO meualuno;
	leitura = fopen(nome_arquivo, "rb");
	escrita = fopen(nome_arquivo, "wb");
	while(fread(&meualuno,sizeof(ALUNO),1,leitura)!=0){
		if(strcmp(nome,meualuno.nome) != 0){
			fwrite(&meualuno,sizeof(ALUNO),1,escrita);
		}
	}
	fclose(leitura);
	fclose(escrita);
	unlink(nome_arquivo);
	rename("novo.txt", nome_arquivo);
	*num_alunos-=1;
}

void alterar(char * nome_arquivo, int * num_alunos){
	excluir(nome_arquivo, num_alunos);
	incluir(nome_arquivo, num_alunos);
}
int main(){
	while(1){
	int num_alunos = 3;
	printf("Escreva i para incluir, a para alterar, c para consultar ou e para excluir\n");
	char operacao = getc(stdin);
	if(operacao == 'i'){
		incluir("salvo_em_b",&num_alunos);
	}
	else if(operacao=='c'){
		consulta("salvo_em_b",num_alunos);
	}
	else if(operacao=='e'){
		excluir("salvo_em_b",&num_alunos);
	}
	else if(operacao=='a'){
		alterar("salvo_em_b",&num_alunos);
	}
	}
}