#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Função registra somente números inteiros;
int readInt(){
    int num;
    while (scanf("%d", &num) != 1){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\n\t\t\t\t\tPor favor, digite um numero: ");
    }
    return num;
}

void newClient() {
    char name[100], adress[100], city[100], state[100], bday[8], plan[10];
    char gender;
    char cpf[14];
    int i;
    int newUsers;

    printf("\n");
    printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
    printf("\n");
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t                                    \n");
    printf("\t\t\t\t\tQuantos clientes você deseja cadastrar?: ");

    newUsers = readInt();
    system("cls");

    for(i = 0; i < newUsers; i++)
    {
        printf("\n");
        printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
        printf("\n");
        printf("\t\t\t\t\t=============================================\n");
        printf("\t\t\t\t\t\t                                    \n");
        printf("\t\t\t\t\tNome Completo: ");
        fflush(stdin);
        fgets(name, 49, stdin);

        printf("\t\t\t\t\tEndereço: ");
        fflush(stdin);
        fgets(adress, 49, stdin);

        printf("\t\t\t\t\tCidade: ");
        fflush(stdin);
        fgets(city, 49, stdin);

        printf("\t\t\t\t\tEstado: ");
        fflush(stdin);
        fgets(state, 49, stdin);

        printf("\t\t\t\t\tCPF/CNPJ: ");
        fflush(stdin);
        fgets(cpf, 49, stdin);

        printf("\t\t\t\t\tData de Nascimento: ");
        fflush(stdin);
        fgets(bday, 49, stdin);

        printf("\t\t\t\t\tSexo: ");
        fflush(stdin);
        //fgets(gender, 49, stdin);
        gender = getchar();

        printf("\t\t\t\t\tPlano: ");
        fflush(stdin);
        fgets(plan, 49, stdin);
    }
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
    printf("\n");
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t                                    \n");
    printf("\t\t\t\t\tVerifique se os dados estão corretos: \n");
    printf("\t\t\t\t\t\t                                    \n");
        for(i = 0; i < newUsers; i++)
        {
            printf("\t\t\t\t\tNome Completo: %s", name);
            printf("\t\t\t\t\tEndereço: %s", adress);
            printf("\t\t\t\t\tCidade: %s", city);
            printf("\t\t\t\t\tEstado: %s", state);
            printf("\t\t\t\t\tCPF/CNPJ: %s", cpf);
            printf("\t\t\t\t\tData de Nascimento: %s", bday);
            printf("\t\t\t\t\tSexo: %c\n", gender);
            printf("\t\t\t\t\tPlano: %s\n", plan);
        }
    getch();
    fflush(stdin);
    system("cls");
}
