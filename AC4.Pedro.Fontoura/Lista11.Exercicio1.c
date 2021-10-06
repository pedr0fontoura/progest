#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct elemento
{
    float info;            // Valor real armazenado
    struct elemento *prox; // Ponteiro para o próximo elemento
};
typedef struct elemento Elemento;

int lista_nao_filtrada(Elemento *lst, float min, float max);
Elemento *filtra(Elemento *lst, float min, float max);
Elemento *lst_insere(Elemento *lst, float val);
Elemento *lst_cria(void);
void lst_imprime_linha(Elemento *lst);
void lst_libera(Elemento *lst);

int main()
{
    Elemento *lst = lst_cria();
    float minimo = 4.0f;
    float maximo = 6.0f;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        float numero = (float)(rand() % 10);
        lst = lst_insere(lst, numero);
    }
    printf("Gerando uma lista aleatoria");
    printf("\n");
    lst_imprime_linha(lst);
    lst = filtra(lst, minimo, maximo);
    printf("\n");
    printf("Filtrando a lista, Minimo = %.2f  Maximo = %.2f", minimo, maximo);
    printf("\n");
    lst_imprime_linha(lst);

    lst_libera(lst);
}

Elemento *filtra(Elemento *lst, float min, float max)
{
    Elemento *ant = NULL; // ponteiro para elemento anterior
    Elemento *p = lst;    // ponteiro para percorrer a lista
    // procura elemento na lista, guardando a referencia do anterior
    while (lista_nao_filtrada(lst, min, max))
    {
        ant = NULL;
        p = lst;
        while (p != NULL && !(p->info < min || p->info > max))
        {
            ant = p;
            p = p->prox;
        }
        // verifica se acha elemento
        if (p == NULL)
            return lst; // não achou: retorna lista original
        // retira elemento
        if (ant == NULL)
        {
            lst = p->prox; // retira o elemento da lista
        }
        else
        {
            ant->prox = p->prox; // retira elemento do meio da lista
        }
        free(p);
    }
    return lst;
}

Elemento *lst_cria(void)
{
    return NULL;
}

int lista_nao_filtrada(Elemento *lst, float min, float max)
{
    Elemento *p;
    for (p = lst; p != NULL; p = p->prox)
    {
        if (p->info < min || p->info > max)
        {
            return 1;
        }
    }
    return 0;
}

void lst_imprime_linha(Elemento *lst)
{
    Elemento *p;
    for (p = lst; p != NULL; p = p->prox)
    {
        printf("[%.2f] ", p->info);
    }
    printf("\n");
}

Elemento *lst_insere(Elemento *lst, float val)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL)
    {
        printf("Falha na alocacao");
        exit(1);
    }

    novo->info = val;
    novo->prox = lst;
    return novo;
}

void lst_libera(Elemento *lst)
{
    Elemento *p = lst;
    Elemento *t;
    while (p != NULL)
    {
        t = p->prox; // guarda referência para o próximo elemento
        free(p);     // libera a memória apontada por p
        p = t;       // faz p apontar para o próximo
    }
}
