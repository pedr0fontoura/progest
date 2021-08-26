#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int mat;       /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;

struct prova
{
    Aluno a;              /* Aluno que fez a prova */
    float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;

void ordena(int n, Prova **v);

int compara(Prova *n, Prova *x);

void troca(Prova **p1, Prova **p2);

int main()
{   
    int n = 7;
    Prova **provas = (Prova **) malloc(n * sizeof(Prova *));
    
    Aluno aluno1 = {1, "Paulo"};
    Prova prova1 = {aluno1, 100, 2, 3 ,4};
    
    Aluno aluno2 = {2, "Diogo"};
    Prova prova2 = {aluno2, 12, 2, 3 ,4};
    
    Aluno aluno3 = {3, "Ana"};
    Prova prova3 = {aluno3, 50, 2, 3 ,4};
    
    Aluno aluno4 = {4, "Antonio"};
    Prova prova4 = {aluno4, 50, 2, 3 ,4};
    
    Aluno aluno5 = {5, "Roberto"};
    Prova prova5 = {aluno5, 12, 2, 3 ,4};
    
    Aluno aluno6 = {6, "Roberta"};
    Prova prova6 = {aluno6, 12, 2, 3 ,4};
    
    Aluno aluno7 = {7, "Kyaru"};
    Prova prova7 = {aluno7, 50, 50, 50 ,50};

    provas[0] = &prova1;
    provas[1] = &prova2;
    provas[2] = &prova3;
    provas[3] = &prova4;
    provas[4] = &prova5;
    provas[5] = &prova6;
    provas[6] = &prova7;

    ordena(n, provas);

    for(int i = 0; i < n; i++)
    {
        printf("%s", provas[i]->a.nome);
        printf("\n");
    }

    return 0;
}

void ordena(int n, Prova **v)
{
    int fim, i;
    for (fim = n - 1; fim > 0; fim--)
        for (i = 0; i < fim; i++)
            if (compara(v[i], v[i + 1]))
                troca(&v[i], &v[i + 1]);
}

int compara(Prova *n, Prova *x)
{
    int soman = n->q1 + n->q2 + n->q3 + n->q4;
    int somax = x->q1 + x->q2 + x->q3 + x->q4;
    
    if (soman <= somax)
    {
        if(soman == somax)
        {
            Aluno alunon = n-> a;
            Aluno alunox = x -> a;
            
            
            int limit = strlen(alunon.nome);
            if(strlen(alunox.nome) > limit)
                limit = strlen(alunox.nome);
                
            
            for(int i = 0; i < limit; i++)
            {
                if(alunon.nome[i] == alunox.nome[i])
                    continue;
                    
                if(alunon.nome[i] > alunox.nome[i])
                    return 1;
                else
                    return 0;
            }
            
            if(strlen(alunon.nome) <= strlen(alunox.nome))
                return 1;
            else
                return 0;
        }
    }
    else
    {
        return 0;
    }
}

void troca(Prova **p1, Prova **p2)
{
    Prova *auxiliar = *p1;

    *p1 = *p2;
    *p2 = auxiliar;
}
