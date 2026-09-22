/*Na Teoria de Sistemas define-se como elemento minimax de uma matriz o menor elemento da linha em
que se encontra o maior elemento da matriz. Escreva um programa que preencha uma matriz m(15,15)
por leitura e determina o seu elemento minimax. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIN 15
#define COL 15

#define MIN -99
#define MAX 99

int main(void) {
    int matriz[LIN][COL], maior[3] = {MIN}, minimax[3] = {MAX}; // minimax/maior = {num, lin, col}
    srand(time(NULL));

    printf("\n ---- MATRIZ ---- \n");
    for (int l = 0; l < LIN; l++) 
    {
        for (int c = 0; c < COL; c++) 
        {
            matriz[l][c] = MIN + (rand() % (MAX - MIN + 1)); // construir a matriz
            printf(" %3d", matriz[l][c]);

            if (matriz[l][c] > maior[0]) 
            { // encontrar o maior da matriz
                maior[0] = matriz[l][c];
                maior[1] = l;
                maior[2] = c;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < COL; i++) 
    { // encontrar o minimax
        if (matriz[maior[1]][i] < minimax[0]) 
        {
            minimax[0] = matriz[maior[1]][i];
            minimax[1] = maior[1];
            minimax[2] = i;
        }
    }
    
    printf("\n ---- RESULATDOS ---- \n");
    printf("MAIOR DA MATRIZ: %3d [%2d] [%2d]\n", maior[0], maior[1], maior[2]);
    printf("MINIMAX:         %3d [%2d] [%2d]\n", minimax[0], minimax[1], minimax[2]);

    return 0;
}