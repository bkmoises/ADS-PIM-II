#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char user[30];
  char pass[50];
} Login;

int main() {
  Login login;
  int try = 3;

  printf("Bem Vindo!\n");
  printf("Para continuar, digite seu login e senha.\n\n");

  while (try > 0) {
    printf("-----------------------------------------\n");
    printf("Login: ");
    scanf("%s", &login.user);
    printf("Senha: ");
    scanf("%s", &login.pass);

    if (strcmp(login.user, "admin") == 0 && strcmp(login.pass, "123") == 0) {
      int menu;

      printf("Login efetuado com sucesso\n");

      system("sleep 3");
      system("clear");

      do {
        system("clear");

        printf("Infinite Pay\n\n");

        printf("(1) Cadastrar novo cliente.\n");
        printf("(2) Alterar plano.\n");
        printf("(3) Consulta.\n");
        printf("(4) Arir novo chamado.\n");
        printf("\n(0) Sair.\n");
        fflush(stdin);

        // menu = getchar();
        // TODO Alterar para getchart
        scanf("%d", &menu);
      } while (menu != 0 && menu != 1 && menu != 2 && menu != 3 && menu != 4);

      switch (menu) {
      case 1:
        printf("Cadastrar novo cliente\n");
        printf("Nome Completo: \n");
        printf("Data Nascimento: \n");
        printf("Sexo: \n");
        printf("Endereço: \n");
        system("clear");
        printf("Plano: \n");
        printf(": \n");
        printf(": \n");
        printf(": \n");
        break;

      case 2:
        printf("Alterar plano");
        printf(": \n");
        break;

      case 3:
        printf("Consulta");
        break;

      case 4:
        printf("Abrir novo chamado");
        break;

      case 0:
        system("exit");
        break;

      default:
        printf("Opção Invalida!");
      }

      return 0;
    } else {
      if (try > 0) {
        printf("\nUsuario ou senha incorretos. Tente Novamente!\n");
        try--;
      }
      if (try == 1) {
        printf("O programa será encerrado caso erre a senha novamente.\n");
      }
    }
  }
  system("clear");
  printf("Número de tentativas excedida.\nFinalizando...\n");
  system("sleep 3");
  return -1;
}
