#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
} Aluno;
typedef struct Materia
{
    Aluno *V;       // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos     // Número de alunos matriculados no curso.
} Materia;

Aluno* fillAluno(){
    Aluno *a = (Aluno*) malloc(sizeof(Aluno));
    if (a == NULL){
        printf("Alocacao falhou");
    }
    a->vNotas = (float*) malloc(5 * sizeof(float));
    if (a->vNotas == NULL){
        printf("Alocacao falhou");
    }
    printf("Qual a matricula do aluno: ");
    scanf("%d", &a->matricula);
    printf("Digite as notas do aluno");
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &a->vNotas[i]);
    }
    printf("Qual o nome do aluno: ");
    scanf(" %s", a->nome);
    return a;
}

Materia * fillMateria(int numAlunos){
    Materia * m = (Materia*) malloc(sizeof(Materia));
    if (m == NULL){
        printf("Alocacao falhou");
    }
    m->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    if (m->V == NULL){
        printf("Alocacao falhou");
    }
    m->nAlunos = numAlunos;
    for (int i = 0; i < numAlunos; i++){
        printf("Dados do aluno %d", i+1);
        printf("\n");
        m->V[i] = *fillAluno();
        printf("\n");
    }
    for (int i = 0; i < 5; i++){
        m->media[i] = 0.0;
    }
    return m;
}

void mediaMateria(Materia *m1){
    for (int j = 0; j < 5; j++){
        m1->media[j] = 0.0;
        for (int i = 0; i < m1->nAlunos; i++){
            m1->media[j] += m1->V[i].vNotas[j];
        }
        m1->media[j] /= m1->nAlunos;
    }
}

void mostraMateria(Materia *m1){
    for (int i = 0; i < m1->nAlunos; i++){
        printf("\n");
        printf("Matricula: %d", m1->V[i].matricula);
        printf("\n");
        printf("Nome: %s", m1->V[i].nome);
        printf("\n");
        for (int j = 0; j < 5; j++){
            printf("Nota %d: %.2f", j+1, m1->V[i].vNotas[j]);
            printf("\n");
        }
    }
}

int main(){
    Materia *mat = fillMateria(3);
    mediaMateria(mat);
    mostraMateria(mat);
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("Media da %d prova: %.2f", i+1, mat->media[i]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++){
        free(mat->V[i].vNotas);
        free(&mat->V[i]);
    }
    free(mat->V);
    free(mat);

    return 0;
}
