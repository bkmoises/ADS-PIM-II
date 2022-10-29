#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#include "pim-soft.h"

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int try = 3;

  welcomeScreen();

  while (try > 0)
  {

    loginScreen();

    if (strcmp(login.user, "admin") == 0 && strcmp(login.pass, "123") == 0)
    {

      alertMsg("Login efetuado com sucesso!", 1000);

      do
      {
        mainMenu();

        switch (input)
        {
        case 1:
          newClient();
          break;
        case 2:
          editPlan();
          break;
        case 3:
          searchClient();
          break;
        case 4:
          newTicket();
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
  alertMsg("Número de tentativas excedida.\nFinalizando...\n", 3000);
  return -1;
}
