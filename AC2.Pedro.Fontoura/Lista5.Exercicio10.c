/* 
  Fazer um programa para cadastro e diálogo de login. O programa deve:
  a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
  sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente os
  caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.

  b. Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
  com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.

  c. Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos
  descritos nos itens a e b.

  d. Comparar o nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
  com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário, informar “Acesso
  negado”.
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define STRING_SIZE 9

void prompt(char * buffer, int is_password) {
  int i = 0;

  while (i < STRING_SIZE) {
    int c = getch();

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
      buffer[i] = (char)c;

      if (is_password) {
        printf("*");
      } else {
        printf("%c", c);
      }

      i++;
    }

    if (c == '\r') {
      buffer[i] = '\0';
      break;
    }
  }
}

int main(void) {
  char user[STRING_SIZE];
  char password[STRING_SIZE];

  char auth_user[STRING_SIZE];
  char auth_password[STRING_SIZE];

  printf("Cadastrar usuário\n");

  printf("\nDigite o nome de usuário: ");
  prompt(user, 0);

  printf("\nDigite a senha: ");
  prompt(password, 1);

  printf("\n\nLogin\n");

  printf("\nDigite o nome de usuário: ");
  prompt(auth_user, 0);

  printf("\nDigite a senha: ");
  prompt(auth_password, 1);

  if (strcmp(user, auth_user) == 0 && strcmp(password, auth_password) == 0) {
    printf("\n\nOK!\n");
  } else {
    printf("\n\nACESSO NEGADO!\n");
  }

  return 0;
}