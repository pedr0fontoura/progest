#include <stdio.h>
#include <stdlib.h>

struct data
{
  int dd, mm, aa;
};

typedef struct data Data;

struct compromisso
{
  char descricao[81];
  Data data;
};

typedef struct compromisso Compromisso;

int compara_data(Data data_a, Data data_b)
{
  if (data_a.aa < data_b.aa)
  {
    return -1;
  }
  else if (data_a.aa > data_b.aa)
  {
    return 1;
  }

  if (data_a.mm < data_b.mm)
  {
    return -1;
  }
  else if (data_a.mm > data_b.mm)
  {
    return 1;
  }

  if (data_a.dd < data_b.dd)
  {
    return -1;
  }
  else if (data_a.dd > data_b.dd)
  {
    return 1;
  }

  return 0;
}

Compromisso *busca(int n, Compromisso **vet, int d, int m, int a)
{
  int left = 0;
  int right = n;

  int middle = right / 2;

  Data date;

  date.dd = d;
  date.mm = m;
  date.aa = a;

  while (left <= right)
  {
    if (vet[middle]->data.dd == d && vet[middle]->data.mm == m && vet[middle]->data.aa == a)
      return vet[middle];

    if (compara_data(vet[middle]->data, date) > 0)
    {
      left = middle + 1;
    }
    else
    {
      right = middle - 1;
    }
  }

  return NULL;
}

int main(void)
{
  Compromisso **compromissos = (Compromisso **)malloc(4 * sizeof(Compromisso *));

  Compromisso compromisso1 = {"Compromisso 1", {25, 8, 2021}};
  Compromisso compromisso2 = {"Compromisso 2", {26, 8, 2021}};
  Compromisso compromisso3 = {"Compromisso 3", {27, 8, 2021}};
  Compromisso compromisso4 = {"Compromisso 4", {28, 8, 2021}};

  compromissos[0] = &compromisso1;
  compromissos[1] = &compromisso2;
  compromissos[2] = &compromisso3;
  compromissos[3] = &compromisso4;

  printf("COMPROMISSOS:\n");

  for (int i = 0; i < 4; i++)
  {
    Compromisso compromisso = *compromissos[i];

    printf("[%d] Descrição: %s | Data: %d/%d/%d\n", i, compromisso.descricao, compromisso.data.dd, compromisso.data.mm, compromisso.data.aa);
  }

  printf("\n\n");

  Compromisso *compromisso = busca(3, compromissos, 27, 8, 2021);

  printf("COMPROMISSO ENCONTRADO:\n");
  printf("Descrição: %s | Data: %d/%d/%d\n", compromisso->descricao, compromisso->data.dd, compromisso->data.mm, compromisso->data.aa);

  free(compromissos);

  return 0;
}