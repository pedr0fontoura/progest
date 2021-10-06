#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
  int registration;
  char name[100];
} Student;

typedef struct list
{
  Student *info;
  struct list *next;
} List;

List *list_create(void)
{
  return NULL;
}

List *list_insert(List *list, Student *student)
{
  List *element = (List *)malloc(sizeof(List));

  element->info = student;
  element->next = list;

  return element;
}

void list_print(List *list)
{
  List *iterator;

  printf("------------------------- Estudantes -------------------------\n");

  for (iterator = list; iterator != NULL; iterator = iterator->next)
  {
    Student *student = iterator->info;

    printf("Matrícula: %d | Nome: %s\n", student->registration, student->name);
  }

  printf("--------------------------------------------------------------\n");
}

Student *list_search_by_name(List *list, char name[100])
{
  List *iterator;

  Student *result = NULL;

  for (iterator = list; iterator != NULL; iterator = iterator->next)
  {
    Student *student = iterator->info;

    if (strstr(student->name, name))
    {
      result = student;
    }
  }

  return result;
}

Student *list_search_by_registration(List *list, int registration)
{
  List *iterator;

  Student *result = NULL;

  for (iterator = list; iterator != NULL; iterator = iterator->next)
  {
    Student *student = iterator->info;

    if (student->registration == registration)
    {
      result = student;
    }
  }

  return result;
}

List *list_remove(List *list, Student *student)
{
  List *last = NULL;
  List *iterator = list;

  while (iterator != NULL && iterator->info != student)
  {
    last = iterator;
    iterator = iterator->next;
  }

  if (iterator == NULL)
  {
    return list;
  }

  if (last == NULL)
  {
    list = iterator->next;
  }
  else
  {
    last->next = iterator->next;
  }

  free(iterator);

  return list;
}

void list_free(List *list)
{
  List *iterator = list;

  List *tmp;

  while (iterator != NULL)
  {
    tmp = iterator->next;

    free(iterator);

    iterator = tmp;
  }
}

int read_line(FILE *file, char *registration, char *student)
{
  // Assuming the file structure is {registration},{name}
  fscanf(file, "%99[^,\n]", registration);
  fscanf(file, "%*c");
  fscanf(file, "%99[^,\n]", student);

  // Return fscanf status code
  return fscanf(file, "%*c");
}

int main(void)
{
  List *list = list_create();

  int status;
  char registration[100];
  char name[100];

  printf("Reading Lista11.Exercicio3.txt\n");

  FILE *file = fopen("Lista11.Exercicio3.txt", "r");

  do
  {
    if (status == EOF)
      break;

    status = read_line(file, registration, name);

    int parsed_registration = atoi(registration);

    Student *student = (Student *)malloc(sizeof(Student));

    student->registration = parsed_registration;
    strcpy(student->name, name);

    list = list_insert(list, student);
  } while (status != EOF);

  fclose(file);

  list_print(list);

  Student *student_to_be_removed = list_search_by_name(list, "Pedro Fontoura Faria Ribeiro Dias");
  list = list_remove(list, student_to_be_removed);

  Student *student_to_be_updated = list_search_by_registration(list, 100000001);
  strcpy(student_to_be_updated->name, "Ricardo Magalhaes Santos Filho (atualizado)");

  list_print(list);

  list_free(list);

  return 0;
}