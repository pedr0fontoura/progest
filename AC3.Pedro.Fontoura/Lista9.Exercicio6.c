#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    int codigo;
    char nome[81];
};
typedef struct pessoa Pessoa;

Pessoa *busca(int n, Pessoa **vet, int codigo){
    int inicio = 0; // Considera todo o vetor no inicio
    int fim = n - 1;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (codigo < vet[meio]->codigo){
            fim = meio - 1;
        }
        else if (codigo > vet[meio]->codigo){
            inicio = meio + 1;
        }
        else{
            return vet[meio];
        }
    }
    return NULL;
}

int main(){
    int n = 4;
    Pessoa **pessoas = (Pessoa **)malloc(n * sizeof(Pessoa *));
    Pessoa pessoa0 = {0, "Roberta"};
    Pessoa pessoa1 = {1, "Juliana"};
    Pessoa pessoa2 = {2, "Alejandro"};
    Pessoa pessoa3 = {3, "Claudio"};
    pessoas[0] = &pessoa0;
    pessoas[1] = &pessoa1;
    pessoas[2] = &pessoa2;
    pessoas[3] = &pessoa3;
    Pessoa *pPessoa = busca(n, pessoas, 2);
    printf("%s", pPessoa->nome);
    printf("\n");
}
