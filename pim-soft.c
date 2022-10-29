#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

typedef struct
{
  char user[30];
  char pass[50];
} Login;

int input = 0;

int main()
{
  setlocale(LC_ALL, "Portuguese");

  Login login;
  int try = 3;

  printf("\t\t\t\t\t\t\t\t Bem Vindo!\n");
  printf("\t\t\t\t\t\t Pressione a tecla 'Enter' para continuar....");
  getchar();
  system("cls");

  while (try > 0)
  {

    printf("\t\t\t\t\t\t Para continuar, digite seu login e senha: \n");
    printf("\t\t\t\t\t\t============================================\n");
    ;
    printf("\t\t\t\t\t\tLogin: ");
    scanf("%s", &login.user);
    printf("\t\t\t\t\t\tSenha: ");
    scanf("%s", &login.pass);

    system("cls");

    if (strcmp(login.user, "admin") == 0 && strcmp(login.pass, "123") == 0)
    {

      printf("Login efetuado com sucesso\n");
      Sleep(1000);
      system("cls");

      do
      {
        printf("\n");
        printf("\t\t\t\t\t\t\t\t  INIFITE PAY\n");
        printf("\n");
        printf("\t\t\t\t\t\t============================================\n");
        printf("\t\t\t\t\t\t|\t                                   |\n");
        printf("\t\t\t\t\t\t|\t (1) Cadastrar novo cliente        |\n");
        printf("\t\t\t\t\t\t|\t (2) Alterar plano.                |\n");
        printf("\t\t\t\t\t\t|\t (3) Consulta                      |\n");
        printf("\t\t\t\t\t\t|\t (4) Arir novo chamado             |\n");
        printf("\t\t\t\t\t\t|\t (5) Logout                        |\n");
        printf("\t\t\t\t\t\t|\t (0) Sair                          |\n");
        printf("\t\t\t\t\t\t|\t                                   |\n");
        printf("\t\t\t\t\t\t============================================\n");
        printf("\n\n");
        printf("\t\t\t\t\t\tSelecione uma opção: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");

        switch (input)
        {
        case 1:
          printf("\n");
          printf("\t\t\t\t\t\t\t  CADASTRAR CLIENTE\n");
          printf("\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\t\t\t\t\t|\t                                    |\n");
          printf("\t\t\t\t\t| Nome Completo:                            |\n");
          getch();
          printf("\t\t\t\t\t| Data Nascimento:                          |\n");
          getch();
          printf("\t\t\t\t\t| Sexo:                                     |\n");
          getch();
          printf("\t\t\t\t\t| CPF:                                      |\n");
          getch();
          printf("\t\t\t\t\t| Endereço:                                 |\n");
          getch();
          printf("\t\t\t\t\t| Plano:                                    |\n");
          printf("\t\t\t\t\t|    (1) Bronze                             |\n");
          printf("\t\t\t\t\t|    (2) Prata                              |\n");
          printf("\t\t\t\t\t|    (3) Ouro                               |\n");
          getch();
          fflush(stdin);
          system("cls");
          break;
        case 2:
          printf("\n");
          printf("\t\t\t\t\t\t\t  ALTERAR PLANO\n");
          printf("\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\t\t\t\t\t| Plano Atual: Prata                        |\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\t\t\t\t\t| Selecione o novo plano:                   |\n");
          printf("\t\t\t\t\t|                                           |\n");
          printf("\t\t\t\t\t| (1) Bronze                                |\n");
          printf("\t\t\t\t\t| (2) Ouro                                  |\n");
          printf("\t\t\t\t\t|                                           |\n");
          printf("\t\t\t\t\t|                                           |\n");
          printf("\t\t\t\t\t| (0) Cancelar                              |\n");
          getch();
          fflush(stdin);
          system("cls");
          break;
        case 3:
          printf("\n");
          printf("\t\t\t\t\t\t\t  CONSULTAR\n");
          printf("\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\t\t\t\t\t| Digite o CPF:                             |\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\n");
          getch();
          fflush(stdin);
          system("cls");
          break;
        case 4:
          printf("\n");
          printf("\t\t\t\t\t\t\t  NOVO CHAMADO\n");
          printf("\n");
          printf("\t\t\t\t\t=============================================\n");
          printf("\t\t\t\t\t|\t                                    |\n");
          printf("\t\t\t\t\t| Nome Completo:                            |\n");
          getch();
          printf("\t\t\t\t\t| Telefone:                                 |\n");
          getch();
          printf("\t\t\t\t\t| E-mail:                                   |\n");
          getch();
          printf("\t\t\t\t\t| Descrição:                                |\n");
          getch();
          fflush(stdin);
          system("cls");
          break;
        case 5:
          input = 0;
          break;
        case 0:
          exit(EXIT_SUCCESS);
        default:
          printf("\n\t\t\tOpção Invalida!\n\n");
          fflush(stdin);
        }

      } while (input != 0);
    }
    else
    {
      if (try > 0)
      {
        printf("\nUsuario ou senha incorretos. Tente Novamente!\n");
        try--;
      }
      if (try == 1)
      {
        printf("O programa será encerrado caso erre a senha novamente.\n\n");
      }
    }
  }

  system("cls");
  printf("Número de tentativas excedida.\nFinalizando...\n");
  Sleep(3000);
  return -1;
}
