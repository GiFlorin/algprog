#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 101

int main()
{
    char str[TAM] = {0}, res[TAM] = {0};
    int cont = 0;
    fgets(str, TAM, stdin);

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] != '\0') && (str[i] != '\n') && (str[i] != '\r'))
            if ((str[i] != 'a') && (str[i] != 'e') && (str[i] != 'i') && (str[i] != 'o') && (str[i] != 'u') && (str[i] != 'y'))
            {
                res[cont] = '.';
                res[cont + 1] = str[i];
                cont += 2;
            }
    }
    str[cont] = '\0';
    printf("%s", res);

    return 0;
}