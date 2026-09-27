/*Escreva um programa que recebe um texto, em uma string entrada, e devolva, em
outra string saida, este mesmo texto sem os espaços brancos. O comprimento da
string saida deverá estar atualizado (isto é, a função strlen aplicada a este string
deverá dar o seu valor correto). */

#include <stdio.h>
#include <string.h>

#define TAM 40

int main(void) {
    char entrada[TAM] = {0};
    char saida[TAM] = {0};
    int i_saida = 0;

    printf("Digite a sua string:  ");
    fgets(entrada, TAM, stdin);

    for (int i = 0; i < strlen(entrada) + 1; i++) // para contar o '\0
    {
        if (entrada[i] != ' ' && entrada[i] != '\n') {
            saida[i_saida] = entrada[i];
            i_saida++;
        } 
    }
    printf("Comprimento entrada = %d\n", strlen(entrada));
    printf("Saida: %s\n", saida);
    printf("Comprimento saida = %d\n", strlen(saida));

    return 0;
}