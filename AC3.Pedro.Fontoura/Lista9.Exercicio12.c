#include <stdio.h>
#include <stdlib.h>

typedef struct Livro{
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
} Livro;

typedef struct Biblioteca{
    Livro **V;  // Armazena a informação de n livros !!
    int nLivros // Número de livros existentes na biblioteca.
} Biblioteca;

Livro * fillLivro(){
    Livro *l = (Livro*) malloc(sizeof(Livro));
    if (l == NULL){
        printf("Alocacao falhou");
    }
    printf("Qual o ano do livro: ");
    scanf("%d", &l->ano);
    printf("Qual o titulo do livro: ");
    scanf(" %99[^\n]", l->titulo);
    printf("Qual o autor do livro: ");
    scanf(" %99[^\n]", l->autor);
    printf("Qual a quantidade do livro: ");
    scanf("%d", &l->nVolume);
    printf("Qual o preco do livro: ");
    scanf("%f", &l->preco);
    return l;
}

Biblioteca * fillBiblioteca(int numLivros){
    Biblioteca * b = (Biblioteca*) malloc(sizeof(Biblioteca));
    if (b == NULL){
        printf("Alocacao falhou");
    }
    b->V = (Livro**) malloc(numLivros * sizeof(Livro*));
    if (b->V == NULL){
        printf("Alocacao falhou");
    }
    b->nLivros = numLivros;

    for (int i = 0; i < numLivros; i++){
        printf("Dados do livro %d", i+1);
        printf("\n");
        b->V[i] = fillLivro();
        printf("\n");
    }
    return b;
}

void valorBiblioteca(Biblioteca * b1, int numLivros){
    float valorTotal = 0.0;
    for (int i = 0; i < numLivros; i++){
        valorTotal += b1->V[i]->preco * b1->V[i]->nVolume;
    }
    printf("O Valor da biblioteca eh de R$%.2f", valorTotal);
    printf("\n");
}

Livro * maiorBiblioteca(Biblioteca * b1, int numLivros){
    Livro* ml = b1->V[0];
    for (int i = 0; i < numLivros; i++){
        if (b1->V[i]->nVolume > ml->nVolume){
            ml = b1->V[i];
        }
    }
    return ml;
}

int main(){
    Biblioteca *blib = fillBiblioteca(3); //Determina '3' o numero de titulos
    valorBiblioteca(blib, blib->nLivros);
    Livro * ml = maiorBiblioteca(blib, blib->nLivros);
    if (ml == NULL){
        printf("Alocacao falhou");
    }
    printf("\n\nDados dos livros...\n");
    for (int i = 0; i < blib->nLivros; i++){
        printf("Livro %d:", i+1);
        printf("\n");
        printf("Ano: %d", blib->V[i]->ano);
        printf("\n");
        printf("Titulo: %s", blib->V[i]->titulo);
        printf("\n");
        printf("Autor: %s", blib->V[i]->autor);
        printf("\n");
        printf("Exemplares: %d", blib->V[i]->nVolume);
        printf("\n");
        printf("Preco: %.2f", blib->V[i]->preco);
        printf("\n");
        printf("\n");
    }
    printf("Titulo com o maior numero de exemplares:");
    printf("\n");
    printf("%s",  ml->titulo);
    printf("\n");
    for (int i = 0; i < blib->nLivros; i++){
        free(blib->V[i]);
    }
    free(blib->V);
    free(blib);

    return 0;
}
