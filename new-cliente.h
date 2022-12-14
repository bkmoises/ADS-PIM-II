#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char *STRUCT_FORMAT_IN = "(%s; %s; %s; %s; %s; %s; %d; %s)\n";

// Função registra somente n�meros inteiros;
int readInt()
{
    int num;
    while (scanf("%d", &num) != 1)
    {
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\n\t\t\t\t\tPor favor, digite um numero: ");
    }
    return num;
}

typedef struct
{
    char name[100];
    char adress[100];
    char city[20];
    char state[20];
    char gender[10];
    char cpf[15];
    int bday;
    char plan[10];
} Register;

void newClient()
{
    Register usersRecord[10] = {};
    int i;
    int newUsers;
    int userIndex = 0;
    char genderChoice;
    char confirmCh;
    int planChoice = 0;

    printf("\n");
    printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
    printf("\n");
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t                                    \n");
    printf("\t\t\t\t\tQuantos clientes voc� deseja cadastrar?: ");

    newUsers = readInt();
    system("cls");

    for (i = 0; i < newUsers; i++)
    {
        printf("\n");
        printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE[%d]\n", userIndex + 1);
        printf("\n");
        printf("\t\t\t\t\t=============================================\n");
        printf("\t\t\t\t\t\t                                    \n");
        printf("\t\t\t\t\tNome Completo: ");
        fflush(stdin);
        fgets(usersRecord[userIndex].name, 100, stdin);
        usersRecord[userIndex].name[strcspn(usersRecord[userIndex].name, "\n")] = '\0';

        printf("\t\t\t\t\tEndere�o: ");
        fflush(stdin);
        fgets(usersRecord[userIndex].adress, 49, stdin);
        usersRecord[userIndex].adress[strcspn(usersRecord[userIndex].adress, "\n")] = '\0';

        printf("\t\t\t\t\tCidade: ");
        fflush(stdin);
        fgets(usersRecord[userIndex].city, 49, stdin);
        usersRecord[userIndex].city[strcspn(usersRecord[userIndex].city, "\n")] = '\0';

        printf("\t\t\t\t\tEstado: ");
        fflush(stdin);
        fgets(usersRecord[userIndex].state, 49, stdin);
        usersRecord[userIndex].state[strcspn(usersRecord[userIndex].state, "\n")] = '\0';

        printf("\t\t\t\t\tCPF/CNPJ: ");
        fflush(stdin);
        fgets(usersRecord[userIndex].cpf, 14, stdin);
        usersRecord[userIndex].cpf[strcspn(usersRecord[userIndex].cpf, "\n")] = '\0';

        printf("\t\t\t\t\tData de Nascimento: ");
        fflush(stdin);
        scanf("\n%d", &usersRecord[userIndex].bday);

        printf("\t\t\t\t\tSexo (M/F): ");
        fflush(stdin);

    genderCh:
        genderChoice = getch();
        switch (genderChoice)
        {
        case 'm':
            strcpy(usersRecord[userIndex].gender, "Masculino");
            break;
        case 'M':
            strcpy(usersRecord[userIndex].gender, "Masculino");
            break;
        case 'f':
            strcpy(usersRecord[userIndex].gender, "Feminino");
            break;
        case 'F':
            strcpy(usersRecord[userIndex].gender, "Feminino");
            break;
        default:
            goto genderCh;
        }
        printf("\n\t\t\t\t\tPlano: ");
        printf("\n\t\t\t\t\t(1) Bronze ");
        printf("\n\t\t\t\t\t(2) Prata ");
        printf("\n\t\t\t\t\t(3) Ouro ");

    planCh:
        printf("\n\t\t\t\t\tSelecione um plano: ");
        fflush(stdin);
        scanf(" %d", &planChoice);
        switch (planChoice)
        {
        case 1:
            strcpy(usersRecord[userIndex].plan, "Bronze");
            break;
        case 2:
            strcpy(usersRecord[userIndex].plan, "Prata");
            break;
        case 3:
            strcpy(usersRecord[userIndex].plan, "Ouro");
            break;
        default:
            printf("\n\t\t\t\t\tPlano Invalido!");
            goto planCh;
        }
        userIndex++;
    }
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
    printf("\n");
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t                                    \n");
    printf("\t\t\t\t\tVerifique se os dados est�o corretos: \n");
    printf("\t\t\t\t\t\t                                    \n");
    for (i = 0; i < newUsers; i++)
    {
        printf("\n\t\t\t\t\tNome Completo: %s", usersRecord[i].name);
        printf("\n\t\t\t\t\tEndere�o: %s", usersRecord[i].adress);
        printf("\n\t\t\t\t\tCidade: %s", usersRecord[i].city);
        printf("\n\t\t\t\t\tEstado: %s", usersRecord[i].state);
        printf("\n\t\t\t\t\tCPF/CNPJ: %s", usersRecord[i].cpf);
        printf("\n\t\t\t\t\tData de Nascimento: %d", usersRecord[i].bday);
        printf("\n\t\t\t\t\tSexo: %s\n", usersRecord[i].gender);
        printf("\t\t\t\t\tPlano: %s\n", usersRecord[i].plan);
    }
    printf("\n\n\t\t\t\t\t\CONFIRMAR DADOS?\n");
    printf("\n");
    printf("\t\t\t\t\t(S)im\n");
    printf("\t\t\t\t\t(N)�o\n");

confirm:
    fflush(stdin);
    printf("\n\t\t\t\t\t ");
    confirmCh = getch();
    switch (confirmCh)
    {
    case 's':
        for (i = 0; i < newUsers; i++)
        {
            FILE *clientDb;
            clientDb = fopen("database.txt", "ab");
            fprintf(clientDb, STRUCT_FORMAT_IN, usersRecord[i].name, usersRecord[i].adress, usersRecord[i].city, usersRecord[i].state, usersRecord[i].gender, usersRecord[i].cpf, usersRecord[i].bday, usersRecord[i].plan);
            fclose(clientDb);
        }
        break;
    case 'S':
        for (i = 0; i < newUsers; i++)
        {
            FILE *clientDb;
            clientDb = fopen("database.txt", "ab");
            fprintf(clientDb, STRUCT_FORMAT_IN, usersRecord[i].name, usersRecord[i].adress, usersRecord[i].city, usersRecord[i].state, usersRecord[i].gender, usersRecord[i].cpf, usersRecord[i].bday, usersRecord[i].plan);
            fclose(clientDb);
        }
        break;
    case 'n':
        break;
    case 'N':
        break;

    default:
        goto confirm;
    }
    fflush(stdin);
    system("cls");
}
