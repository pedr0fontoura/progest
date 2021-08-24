#include <stdio.h>
#include <stdlib.h>

float* acima_da_media(int n, float *vet, int *tam){

    float media = 0, soma = 0;
    int i, count;

    for(i = 0; i < n; i++){
        soma += vet[i];
    }

    media = soma / n;

    for(i = 0; i < n; i++){
        if(vet[i] > media){
            (*tam)++;
        }
    }

    count = 0;
    float* vetresposta = (float*)malloc((*tam) * sizeof(float));

    for(i = 0; i < n; i++){
        if(vet[i] > media){
            vetresposta[count] = vet[i];
            count++;
        }
    }

    return vetresposta;
}

int main(){

    int n, tam, i;
    float *vet;
    float *acimadamedia;

    scanf("%d", &n);
    vet = (float*)malloc(n * sizeof(float));

    for(i = 0; i < n; i++){
        scanf("%f", &vet[i]);
    }

    tam = 0;
    acimadamedia = acima_da_media(n, vet, &tam);

    for(i = 0; i < tam; i++){
        printf("%.1f\n", acimadamedia[i]);
    }

    return 0;
}