#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// função responsavel por fazer o login de usuário caso as credenciais estajam corretas
int loginProcess()
{
    accessUpload();

    int tam = 0;
    char usuario[80], senha[80], senha2[80];
    memset(usuario, 0x00, sizeof(usuario));
    memset(senha, 0x00, sizeof(senha));

    printf("\t\t\t\t\t\t Para continuar, digite seu login e senha: \n");
    printf("\t\t\t\t\t\t============================================\n");
    printf("\t\t\t\t\t\tLogin: ");
    scanf("%s", &usuario);
    printf("\t\t\t\t\t\tSenha: ");
    fflush(stdin);

    do
    {
        senha[tam] = getch();
        if (senha[tam] == 0x08 && tam > 0) // Backspace
        {
            printf("\b \b");
            senha[tam] = 0x00;
            tam--;
        }
        else if (senha[tam] == 13) // Enter
        {
            senha[tam] = 0x00;
            break;
        }
        else if (senha[tam] != 0x08)
        {
            putchar('*');
            tam++;
        }
    } while (tam < 100);

    int userIndex;

    for (userIndex = 0; userIndex < sizeof(login) / sizeof(login[0]);
         userIndex++)
    {
        if (strcmp(usuario, login[userIndex].user) == 0)
        {
            if (strcmp(senha, login[userIndex].pass) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}
