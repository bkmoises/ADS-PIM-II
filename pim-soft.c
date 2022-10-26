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
      printf("Login efetuado com sucesso\n");
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
