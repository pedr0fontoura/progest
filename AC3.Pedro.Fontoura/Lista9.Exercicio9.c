#include <stdio.h>
#define MAX 4

struct aluno
{
    int matricula;
    float media;
};
typedef struct aluno ALUNO;

void ordena(ALUNO turma[], int tam){
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;
    do{
        foraOrdem = 0;
        for (i = 0; i < 4 - 1 - jaOrdenados; i++){
            if (turma[i].media > turma[i + 1].media){
                temp = turma[i];
                turma[i] = turma[i + 1];
                turma[i + 1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);
}

int main(){
    ALUNO turma[MAX];
    turma[0] = (ALUNO){ 1, 8.0};  //Vai ser o segundo
    turma[1] = (ALUNO){ 2, 5.0};  //Vai ser o quarto
    turma[2] = (ALUNO){ 3, 9.5};  //Vai ser o primeiro
    turma[3] = (ALUNO){ 4, 7.5};  //Vai ser o terceiro
    ordena(turma, MAX);
    for (int i = 0; i < MAX; i++){
        printf("Matricula: %d", turma[i].matricula);
        printf("\n");
        printf("Media: %.1f", turma[i].media);
        printf("\n");
        printf("\n");
    }
}
