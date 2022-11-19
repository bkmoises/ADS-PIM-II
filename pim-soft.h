#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int input = 0;

// Mensagem de boas vindas ao usu�rio ao iniciar o software.
void welcomeScreen()
{
    printf("\t\t\t\t\t\t\t\t Bem Vindo!\n");
    printf("\t\t\t\t\t\t Pressione a tecla 'Enter' para continuar....");
    getch();
    system("cls");
}

// Imprime uma mensagem para o usu�rio por um determinado tempo e limpa a tela na sequ�ncia.
// Parametros:
// message: Mensagem que ser� exibida.
// time: Tempo que a mensagem ser� exibidade.
void alertMsg(message, time)
{
    printf(message);
    Sleep(time);
    system("cls");
}

// Tela de altera��o de plano do cliente
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
    printf("\t\t\t\t\t| Descri��o:                                |\n");
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
    printf("\t\t\t\t\t\t|\t (2) Alterar plano                 |\n");
    printf("\t\t\t\t\t\t|\t (3) Consulta                      |\n");
    printf("\t\t\t\t\t\t|\t (4) Abrir novo chamado            |\n");
    printf("\t\t\t\t\t\t|\t (5) Logout                        |\n");
    printf("\t\t\t\t\t\t|\t (0) Sair                          |\n");
    printf("\t\t\t\t\t\t|\t                                   |\n");
    printf("\t\t\t\t\t\t============================================\n");
    printf("\n\n");
    fflush(stdin);
    printf("\t\t\t\t\t\tSelecione uma opcao: ");
    input = readInt();
    system("cls");
}
