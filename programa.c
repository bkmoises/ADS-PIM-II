#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char user[30];
  char pass[100];
} Login;

int read = 0;
int record = 0;

Login login[100];

void fileUpload() {
  FILE *clientDb;
  clientDb = fopen("database.txt", "r");

  if (clientDb == NULL) {
    printf("Ocorreu um problema ao tentar abrir o arquivo de usuarios.\n");
    return 1;
  }

  do {
    read = fscanf(clientDb, "(%100[^;]; %10[^)])\n", &login[record].user,
                  &login[record].pass);

    if (read == 2)
      record++;

    if (read != 2 && !feof(clientDb)) {
      printf("Formato de arquvio invalido!\n");
      return 1;
    }
  } while (!feof(clientDb));

  fclose(clientDb);
};

void main() {
  fileUpload();

  int tam = 0;
  char usuario[80], senha[80], senha2[80];
  memset(usuario, 0x00, sizeof(usuario));
  memset(senha, 0x00, sizeof(senha));

  printf("Digite o usuario: ");
  scanf("%s", &usuario);
  printf("Digite a senha: ");
  fflush(stdin);

  do {
    senha[tam] = getch();
    if (senha[tam] == 0x08 && tam > 0) // Backspace
    {
      printf("\b \b");
      senha[tam] = 0x00;
      tam--;
    } else if (senha[tam] == 13) // Enter
    {
      senha[tam] = 0x00;
      break;
    } else if (senha[tam] != 0x08) {
      putchar('*');
      tam++;
    }
  } while (tam < 100);

  int userIndex;

  for (userIndex = 0; userIndex < sizeof(login) / sizeof(login[0]);
       userIndex++) {
    if (strcmp(usuario, login[userIndex].user) == 0) {
      if (strcmp(senha, login[userIndex].pass) == 0) {
        printf("Login efetuado com sucesso!");
      } else {
        printf("Login ou senha Invalidos!");
      }
    }
  }
  // if (strcmp(senha, "12345") == 0 && strcmp(usuario, "moises") == 0) {
  //   printf("\n%s, Senha OK!\n", usuario);
  // } else
  // printf("\n%s, Senha Incorreta!!\n", usuario);
}
