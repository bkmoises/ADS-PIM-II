#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char search[14];
char consultMenu;



Register usersRecord[10] = {};
int read = 0;
int record = 0;

void fileUpload()
{
    FILE *clientDb;
    clientDb = fopen("database.txt", "r");

    if (clientDb == NULL)
    {
        printf("Ocorreu um problema ao tentar abrir o arquivo de usuarios.\n");
        return 1;
    }

    do
    {
        read = fscanf(clientDb,
                      "(%100[^;]; %100[^;]; %50[^;]; %50[^;]; %10[^;]; %15[^;]; %d; %10[^)])\n",
                      &usersRecord[record].name,
                      &usersRecord[record].adress,
                      &usersRecord[record].city,
                      &usersRecord[record].state,
                      &usersRecord[record].gender,
                      &usersRecord[record].cpf,
                      &usersRecord[record].bday,
                      &usersRecord[record].plan);

        if (read == 8)
            record++;

        if (read != 8 && !feof(clientDb))
        {
            printf("Formato de arquvio invalido!\n");
            return 1;
        }
    } while (!feof(clientDb));

    fclose(clientDb);
};

void searchClient()
{
    fileUpload();
consultCh:
    printf("\n");
    printf("\t\t\t\t\t\t\t  CONSULTAR\n");
    printf("\n");
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t| *sem espaços ou pontuações.\n");
    printf("\t\t\t\t\t| Digite o CPF: ");
    fflush(stdin);
    fgets(search, 14, stdin);
    search[strcspn(search, "\n")] = '\0';
    printf("\n");
    system("cls");

    int i;
    if (strlen(search) < 10)
    {
    consultMsg:
        printf("CPF\\CNPJ Invalido!\n");
        printf("(N)ova pesquisa.\n");
        printf("(S)air.");
        fflush((stdin));
        consultMenu = getch();
        switch (consultMenu)
        {
        case 's':
            return 0;

        case 'S':
            return 0;

        case 'n':
            system("cls");
            goto consultCh;
        case 'N':
            goto consultCh;
            system("cls");
        default:
            system("cls");
            goto consultMsg;
        }
    }

    for (i = 0; i < sizeof(usersRecord) / sizeof(usersRecord[0]); i++)
    {

        if (strcmp(usersRecord[i].cpf, search) == 0)
        {
            printf("\n");
            printf("\t\t\t\t\t\t\t  CONSULTAR\n");
            printf("\n");
            printf("\t\t\t\t\t=============================================\n");
            printf("\t\t\t\t\tNome: %s\n", usersRecord[i].name);
            printf("\t\t\t\t\tEndereço: %s\n", usersRecord[i].adress);
            printf("\t\t\t\t\tCidade: %s\n", usersRecord[i].city);
            printf("\t\t\t\t\tEstado: %s\n", usersRecord[i].state);
            printf("\t\t\t\t\tSexo: %s\n", usersRecord[i].gender);
            printf("\t\t\t\t\tCPF/CNPJ: %s\n", usersRecord[i].cpf);
            printf("\t\t\t\t\tData de Nascimento: %d\n", usersRecord[i].bday);
            printf("\t\t\t\t\tPlano: %s\n", usersRecord[i].plan);

            printf("\n\n\t\t\t\t\t(N)ova pesquisa.\n");
            printf("\t\t\t\t\tAperte qualquer tecla para sair.");
            fflush((stdin));
            consultMenu = getch();
            switch (consultMenu)
            {
            case 's':
                break;

            case 'S':
                break;

            case 'n':
                system("cls");
                goto consultCh;
            case 'N':
                goto consultCh;
                system("cls");
            default:
                system("cls");
                break;
            }
        }
    }
}
