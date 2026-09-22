/*Preencha (com números aleatórios de 1 a 99, supondo que a semente de números
aleatórios seja 0) uma matriz quadrada (de inteiros) de ordem 10 e obtenha a sua
transposta. Imprima as duas matrizes para averiguação.*/

#define TAM_MATRIZ 10
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    srand(0);
    int matriz[TAM_MATRIZ] [TAM_MATRIZ];
    int matriz_t[TAM_MATRIZ] [TAM_MATRIZ];

    printf("\n-- MATRIZ --\n");

    // construir a matriz
    for (int l = 0; l < TAM_MATRIZ; l++) {
        for (int c = 0; c < TAM_MATRIZ; c++) {
            int n = rand() % 100;
            matriz[l][c] = n;
            printf(" %2d ", n);
        }
        printf("\n");
    }
    printf("\n-- MATRIZ TRANSPOSTA --\n");

    // fazer a transposta
    for (int l = 0; l < TAM_MATRIZ; l++) {
        for(int c = 0; c < TAM_MATRIZ; c++) {
            matriz_t[l][c] = matriz[c][l];
            printf(" %2d ", matriz_t[l][c]);
        }
        printf("\n");
    }
    return 0;
}