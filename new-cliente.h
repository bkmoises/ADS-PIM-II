#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Função registra somente números inteiros;
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
  int cpf[25];
  int bday[9];
  char plan[10];
} Register;

void newClient()
{
  Register usersRecord[10] = {};
  int i;
  int newUsers;
  int userIndex = 0;
  char genderChoice;
  int planChoice = 0;

  printf("\n");
  printf("\t\t\t\t\t\t\tCADASTRAR CLIENTE\n");
  printf("\n");
  printf("\t\t\t\t\t=============================================\n");
  printf("\t\t\t\t\t\t                                    \n");
  printf("\t\t\t\t\tQuantos clientes você deseja cadastrar?: ");

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
    fgets(usersRecord[userIndex].name, 49, stdin);

    printf("\t\t\t\t\tEndereço: ");
    fflush(stdin);
    fgets(usersRecord[userIndex].adress, 49, stdin);

    printf("\t\t\t\t\tCidade: ");
    fflush(stdin);
    fgets(usersRecord[userIndex].city, 49, stdin);

    printf("\t\t\t\t\tEstado: ");
    fflush(stdin);
    fgets(usersRecord[userIndex].state, 49, stdin);

    printf("\t\t\t\t\tCPF/CNPJ: ");
    fflush(stdin);
    fgets(usersRecord[userIndex].cpf, 49, stdin);

    printf("\t\t\t\t\tData de Nascimento: ");
    fflush(stdin);
    fgets(usersRecord[userIndex].bday, 49, stdin);
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
  printf("\t\t\t\t\tVerifique se os dados estão corretos: \n");
  printf("\t\t\t\t\t\t                                    \n");
  for (i = 0; i < newUsers; i++)
  {
    printf("\n\t\t\t\t\tNome Completo: %s", usersRecord[i].name);
    printf("\t\t\t\t\tEndereço: %s", usersRecord[i].adress);
    printf("\t\t\t\t\tCidade: %s", usersRecord[i].city);
    printf("\t\t\t\t\tEstado: %s", usersRecord[i].state);
    printf("\t\t\t\t\tCPF/CNPJ: %s", usersRecord[i].cpf);
    printf("\t\t\t\t\tData de Nascimento: %s", usersRecord[i].bday);
    printf("\t\t\t\t\tSexo: %s\n", usersRecord[i].gender);
    printf("\t\t\t\t\tPlano: %s\n", usersRecord[i].plan);
  }
  getch();
  fflush(stdin);
  system("cls");
}
