#include <stdio.h>
#define TAM 7
#define MAX 1000

float extrair_valor(char str[TAM]);

int main()
{
    // ENTRADA
    int n;
    char sinicial[TAM];
    char depositos[MAX][TAM] = {0};
    scanf("%d", &n);
    fgets(sinicial, TAM, stdin); // saldo inicial

    for (int i = 0; i <= n; i++)
    {
        fgets(depositos[i], TAM, stdin);
    }
    //

    // SAIDA

    return 0;
}

float extrair_valor(char str[TAM])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '$')
        {
        }
    }
}