/*Um texto é composto de palavras de 10 ou menos caracteres. Escreva um
programa que lê um texto de até 100 palavras e depois as imprime em ordem
alfabética. */
#include <stdio.h>
#include <string.h>
#define TEXTO 1101 // 10 * 100 palavras + 100 espacos + '\0'
#define PALAVRA 10 // 10 caracteres
#define N_PAL 100

int main(void) {
    char texto[TEXTO] = {0};
    char palavras[N_PAL][PALAVRA+1] = {0};
    int i_c = 0; // indice comeco palavra corrente
    int i_p = 0; // quantas palavras foram guardadas
    int sorted = 0; // se as palavras estão ordenadas

    printf("Escreva o seu texto:  ");
    fgets(texto, TEXTO, stdin);

    // Separar as palavras em uma array
    for (int i = 0; i < strlen(texto); i++)
    {
        if ((texto[i] == ' ' )|| (texto[i] == '\0') || (texto[i] == '\n')) { // se a palavra acabou
            for (int j = i_c, k = 0; j < i; j++, k++) // copiar a palavra para a lista
            {
                palavras[i_p][k] = texto[j];
            }
            palavras[i_p][strlen(palavras[i_p])+1] = '\0';
            // printf("[%s]\n", palavras[i_p]);
            i_p++;
            i_c = i+1;
        }
    }

    // ordem alfabetica - bubble sort
    do {
        sorted = 1;
        for (int i = 0; i < i_p-1; i++)
        {
            int comparacao = strcmp(palavras[i], palavras[i+1]);
            char aux[PALAVRA+1] = {0};
            
            if(comparacao > 0) { // str1 > str2
                // trocar posicoes
                strcpy(aux, palavras[i]); // aux = palavras[i]
                strcpy(palavras[i], palavras[i + 1]); // palavras[i] = palavras[i + 1]
                strcpy(palavras[i+1], aux); // palavras[i + 1] = aux
                sorted = 0;
            } 
        }
    } while(!sorted);

    // imprimir 
    printf("\n--- PALAVRAS EM ORDEM ALFABETICA ---\n");
    for (int i = 0; i < i_p; i++)
        printf("%d - %s\t\n", i+1, palavras[i]);

    return 0;
}
