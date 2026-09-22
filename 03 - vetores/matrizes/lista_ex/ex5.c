/*Leia uma matriz quadrada de ordem 10 e calcule a sua transposta. Imprima as duas matrizes.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM 10
#define MIN 0
#define MAX 10

int main(void) {
    int matriz[TAM][TAM], matriz_t[TAM][TAM];
    printf(" \033[1;31;43m---- MATRIZ ORIGINAL ----\033[m\n");

    for (int l = 0; l < TAM; l++)
    {
        for (int c = 0; c < TAM; c++)
        {
            matriz[l][c] = MIN + (rand() % (MAX - MIN + 1));
            matriz_t[c][l] = matriz[l][c];

            if (l == c)
                printf("\033[0;32;40m %2d\033[m", matriz[l][c]);
            else
                printf(" %2d", matriz[l][c]);
        }
        printf("\n");
    }

    printf("\n \033[1;31;43m---- MATRIZ TRANSPOSTA ----\033[m\n");  
    for (int l = 0; l < TAM; l++)
    {
        for (int c = 0; c < TAM; c++)
        {
            if (l == c)
                printf("\033[0;32;40m %2d\033[m", matriz_t[l][c]);
            else
                printf(" %2d", matriz_t[l][c]);
        }
        printf("\n");
        
    }
      

    return 0;
}