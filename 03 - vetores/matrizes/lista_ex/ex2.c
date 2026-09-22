/*Preencher por leitura uma matriz m (10,10). 
Forma um vetor (arranjo de uma dimensão) com os elementos das linhas pares da matriz. 
Formar outro vetor com os elementos da diagonal principal somados com os elementos da mesma linha, contidos na diagonal secundária. 
Imprimir a matriz e os 2 vetores. */
// nao quero fazer por leitura, vou fazer numeros aleatorios

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM 10

#define MIN 0
#define MAX 10

int main(void) {
    int matriz[TAM][TAM], diag[TAM]; // matriz e quadrada
    int i_lin_p = 0, lin_p[TAM / 2 * TAM]; // lin_p(linhas pares) = metade do n de linhas * n de valores por linha(colunas)

    srand(time(NULL));
    printf("\n---- MATRIZ PRINCIPAL ----\n");
    for (int l = 0; l < TAM; l++) { // faz a matriz principal
        for (int c = 0; c < TAM; c++) {
            matriz[l][c] = MIN + (rand() % (MAX - MIN + 1));
            printf("%3d ", matriz[l][c]);
        }
        printf("\n");
    }

    // Forma um vetor (arranjo de uma dimensão) com os elementos das linhas pares da matriz. 
    printf("\n ---- VETOR LINHAS PARES ---- \n");
    for (int l = 0; l < TAM; l++) {
        if ((l % 2) == 0) { // linhas pares
            for (int c = 0; c < TAM; c++, i_lin_p++) {
                lin_p[i_lin_p] = matriz[l][c];
                printf("%2d ", lin_p[i_lin_p]);
            }
        }
    }
    //Formar outro vetor com os elementos da diagonal principal somados com os elementos da mesma linha, contidos na diagonal secundária.
    printf("\n ---- VETOR DIAGONAIS ---- \n");
    for (int i = 0, j = TAM - 1; i < TAM; i++, j--) {
        int diag_1 = 0, diag_2 = 0;
        diag_1 = matriz[i][i];
        diag_2 = matriz[i][j];
        diag[i] = diag_1 + diag_2;
        // printf("%d[%d][%d] + %d[%d][%d] = %d \n",diag_1,i, i, diag_2,i, j, diag[i]);
        printf(" %2d", diag[i]);
    }
    return 0;
}