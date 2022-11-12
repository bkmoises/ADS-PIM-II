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

Login login;
int input = 0;

// Mensagem de boas vindas ao usuário ao iniciar o software.
void welcomeScreen()
{
    printf("\t\t\t\t\t\t\t\t Bem Vindo!\n");
    printf("\t\t\t\t\t\t Pressione a tecla 'Enter' para continuar....");
    getchar();
    system("cls");
}

// Tela de login, onde o usuário irá validar sua identidade
void loginScreen()
{
    printf("\t\t\t\t\t\t Para continuar, digite seu login e senha: \n");
    printf("\t\t\t\t\t\t============================================\n");
    ;
    printf("\t\t\t\t\t\tLogin: ");
    scanf("%s", &login.user);
    printf("\t\t\t\t\t\tSenha: ");
    scanf("%s", &login.pass);

    system("cls");
}

// Imprime uma mensagem para o usuário por um determinado tempo e limpa a tela na sequëncia.
// Parametros:
// message: Mensagem que será exibida.
// time: Tempo que a mensagem será exibidade.
void alertMsg(message, time)
{
      printf(message);
      Sleep(time);
      system("cls");
}

// Tela de cadastro de novo cliente.
/* void newClient()
{
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
}
*/
// Tela de alteração de plano do cliente
void editPlan()
{
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
}

// Tela para consulta de cliente cadastrado.
void searchClient()
{
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
}

// Tela para abertura de chamados
void newTicket()
{
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
}

// Tela de menu principal
void mainMenu()
{
        printf("\n");
        printf("\t\t\t\t\t\t\t\t HEADWAY CRED\n");
        printf("\n");
        printf("\t\t\t\t\t\t============================================\n");
        printf("\t\t\t\t\t\t|\t                                   |\n");
        printf("\t\t\t\t\t\t|\t (1) Cadastrar novo cliente        |\n");
        printf("\t\t\t\t\t\t|\t (2) Alterar plano.                |\n");
        printf("\t\t\t\t\t\t|\t (3) Consulta                      |\n");
        printf("\t\t\t\t\t\t|\t (4) Abrir novo chamado            |\n");
        printf("\t\t\t\t\t\t|\t (5) Logout                        |\n");
        printf("\t\t\t\t\t\t|\t (0) Sair                          |\n");
        printf("\t\t\t\t\t\t|\t                                   |\n");
        printf("\t\t\t\t\t\t============================================\n");
        printf("\n\n");
        fflush(stdin);
        printf("\t\t\t\t\t\tSelecione uma opção: ");
        scanf("%d", &input);
        system("cls");
}
