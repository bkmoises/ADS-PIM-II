#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// função responsavel por fazer o login de usuário caso as credenciais estajam corretas
int loginProcess()
{
    accessUpload();

    int size = 0;
    char user[80], passwd[80];
    memset(user, 0x00, sizeof(user));
    memset(passwd, 0x00, sizeof(passwd));

    printf("\t\t\t\t\t\t Para continuar, digite seu login e senha: \n");
    printf("\t\t\t\t\t\t============================================\n");
    printf("\t\t\t\t\t\tLogin: ");
    scanf("%s", &user);
    printf("\t\t\t\t\t\tSenha: ");
    fflush(stdin);

    do
    {
        passwd[size] = getch();
        if (passwd[size] == 0x08 && size > 0) // Backspace
        {
            printf("\b \b");
            passwd[size] = 0x00;
            size--;
        }
        else if (passwd[size] == 13) // Enter
        {
            passwd[size] = 0x00;
            break;
        }
        else if (passwd[size] != 0x08)
        {
            putchar('*');
            size++;
        }
    } while (size < 100);

    int userIndex;

    for (userIndex = 0; userIndex < sizeof(login) / sizeof(login[0]);
         userIndex++)
    {
        if (strcmp(user, login[userIndex].user) == 0)
        {
            if (strcmp(passwd, login[userIndex].pass) == 0)
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
