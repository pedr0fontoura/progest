#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome){
    strcpy(nomes[indice], nome);
}

char *get_sobrenome(char *nome){
    char *sobrenome;
    int i, j;
    for (i = strlen(nome); nome[i] != ' '; i--);
    i++;
    sobrenome = nome + i;
    return sobrenome;
}

main(){
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++){
        nomes[i] = (char *)malloc(sizeof(char) * MAXNOME);
    }
    atribui(nomes, 0, "Fulano Silva");
    atribui(nomes, 1, "Maria do Carmo");
    atribui(nomes, 2, "Beltrano Belmonte");
    atribui(nomes, 3, "Pedro dos Santos");
    for (i = 0; i < MAX; i++){
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d", strlen(sobrenome) > 5 ? i : 0); // 2o printf
    }
    printf("\n%c", nomes[0][3]); // 3o printf
}


/*

EX4 Item C
Resposta: O segundo printf imprimirá '0'.

EX4 Item D
Resposta: O terceiro printf imprimirá 'a'.

*/
