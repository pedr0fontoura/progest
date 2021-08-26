#include <stdio.h>
#include <stdlib.h>


typedef struct data{
    int dia, mes, ano;
} Data;

typedef struct local{
    char ender[81]; // endereço do local de provas
    int sala;       // numero sala
} Local;

typedef struct notas{
    float geral;      // prova de conhecimentos gerais
    float especifica; // prova de conhecimentos especificos
} Notas;

typedef struct candidato{
    int inscr;     // numero de inscricao
    char nome[81]; // nome do candidato
    Data nasc;     // data de nascimento
    Local *loc;    // local de prova
    Notas nt;      // notas de prova
} Candidato;

void mostrarcandidatos(int n, Candidato *vetc){
    for (int i = 0; i < n; i++){
        printf("Candidato de inscricao %d", vetc[i].inscr);
        printf("\n");
        printf("Data de nascimento: %d/%d/%d", vetc[i].nasc.dia, vetc[i].nasc.mes, vetc[i].nasc.ano);
        printf("\n");
        printf("Endereco: %s", vetc[i].loc->ender);
        printf("\n");
        printf("Sala: %d", vetc[i].loc->sala);
        printf("\n");
        printf("Nota geral: %.2f", vetc[i].nt.geral);
        printf("\n");
        printf("Nota especifica: %.2f", vetc[i].nt.especifica);
        printf("\n");
        printf("\n");
    }
}

void alterarlocal(int n, Candidato *vetc){
    int numero;
    int flag = 0;
    printf("Qual o numero de inscricao:");
    scanf("%d", &numero);
    int i;
    for (i = 0; i < n; i++){
        if (vetc[i].inscr == numero){
            flag = 1;
            printf("Qual o novo endereco:");
            scanf(" %s", &vetc[i].loc->ender);
            printf("Qual o numero da nova sala:");
            scanf("%d", &vetc[i].loc->sala);
        }
    }
    if (flag == 0){
        printf("Não existe essa inscricao!");
        printf("\n");
        printf("\n");
    }
}

int main(){
    Candidato c;
    Candidato *vetc;
    int *ptam;
    int opcao = 0;
    c.loc = (Local *)malloc(sizeof(Local));
    while (opcao != 4){
        printf("Menu");
        printf("\n");
        printf("\n");
        printf("Opcoes:");
        printf("\n");
        printf("1 - Escrever os dados dos candidatos");
        printf("\n");
        printf("2 - Mostra os dados dos candidatos");
        printf("\n");
        printf("3 - Altera o endereco dos candidatos");
        printf("\n");
        printf("4 - Terminar o programa");
        printf("\n");
        printf("\n");
        printf("Digite a opcao desejada:");
        scanf("%d", &opcao);
        printf("\n");
        if (opcao == 1){
            int tam;
            printf("Digite o numero de candidatos para serem entrevistados:");
            scanf("%d", &tam); //usuario coloca a quantidade de entrevistados no int tam
            printf("\n");
            ptam = &tam;
            vetc = (Candidato*)malloc(tam*sizeof(Candidato));
            for (int i = 0; i < tam; i++){
                printf("Qual o numero de inscricao:");
                scanf("%d", &c.inscr);
                printf("\n");
                printf("Qual o nome do candidato:");
                scanf(" %s", &c.nome);
                printf("\n");
                printf("Data de nascimento, d/m/a separada com espaço:");
                scanf("%d %d %d", &c.nasc.dia, &c.nasc.mes, &c.nasc.ano);
                printf("\n");
                printf("Qual o endereco:");
                scanf(" %s", &c.loc->ender);
                printf("\n");
                printf("Qual o numero da sala:");
                scanf("%d", &c.loc->sala);
                printf("\n");
                printf("Qual a nota geral do candidato:");
                scanf("%f", &c.nt.geral);
                printf("\n");
                printf("Qual a nota especifica do candidato:");
                scanf("%f", &c.nt.especifica);
                vetc[i] = c;
                printf("\n");
            }
        }
        if (opcao == 2){
            mostrarcandidatos(*ptam, vetc);
        }
        if (opcao == 3){
            alterarlocal(*ptam, vetc);
        }
    }
}
