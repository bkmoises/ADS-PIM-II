#include <stdio.h>
#include <stdlib.h>

// funcão que cria os arquivos database e access caso não existam.
void imputData()
{
    FILE *clientDb;
    clientDb = fopen("database.txt", "ab");
    fclose(clientDb);

    FILE *access;
    access = fopen("access.txt", "ab");
    fclose(access);

    if (clientDb == NULL || access == NULL)
    {
        printf("Erro ao tentar ler o arquivo");
        exit(EXIT_SUCCESS);
    };
}
