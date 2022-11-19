#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#include "pim-soft.h"
#include "new-cliente.h"
#include "file-modules.h"
#include "clientConsult.h"
#include "login.h"

int main()
{
    setlocale(LC_ALL, "");
    imputData();

    int try = 3;

    welcomeScreen();

    while (try > 0)
    {
        if (loginProcess() == 0)
        {
            system("cls");
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
                    printf("\n\t\t\tOpcao Invalida!\n\n");
                    fflush(stdin);
                }

            } while (input != 0);
        }
        else
        {
            if (try > 0)
            {
                system("cls");
                printf("\nUsuario ou senha incorretos. Tente Novamente!\n");
                try--;
            }
            if (try == 1)
            {
                printf("O programa sera encerrado caso erre sua senha novamente.\n\n");
            }
        }
    }

    system("cls");
    alertMsg("Numero de tentativas excedida.\nFinalizando...\n", 3000);
    return -1;
}
