#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int size, float * number,int first,int last){
	int i, j, pivot; 
	float temp;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(number[i]<=number[pivot]&&i<last)i++;
			while(number[j]>number[pivot])j--;
			if(i<j){
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
		temp=number[pivot];
		number[pivot]=number[j];
		number[j]=temp;
		quicksort(size,number,first,j-1);
		quicksort(size,number,j+1,last);
	}
}

float * le_arquivo(){
	FILE * fp;
	fp = fopen("numeros.txt", "rt");
	float * vet;
	size_t len = 0;
	size_t size = 1;
	float media = 0;
	char linha[121];
	vet = realloc(NULL,sizeof(*vet)*size);
	while(fgets(linha,121,fp)!=NULL){
		vet[len++] = atof(linha);
		if(len == size){
			vet = realloc(vet, sizeof(*vet)*(size+=1));
		}
	}
	quicksort(size,vet,0,size-1);
	FILE * bin;
	bin = fopen("salvoBinario.txt","wb");
	fwrite(vet, sizeof(float), size, bin);
	return vet;
}

int main(){
	float * vet = le_arquivo();
	while(1){}
}