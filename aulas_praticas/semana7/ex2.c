/*Escreva um programa que gere uma imagem colorida representada por uma matriz 3D de
inteiros de dimensão 4 x 4 x 3. A imagem possui 16 pixels (4x4) e cada pixel possui os valores dos canais
RGB (vermelho, verde e azul). O programa deve:
a) Gerar os valores dos canais R, G e B de cada pixel com números aleatórios no intervalo [0, 255].
(1.5pts)
b) Calcular e imprimir a média de intensidade de cada canal (R, G e B) separadamente. (1.5pts)
c) Calcular e imprimir o pixel mais brilhante da imagem, isto é, aquele cuja soma R+G+B é máxima,
bem como sua posição na matriz. (1pt)
d) Calcular e imprimir a imagem em escala de cinza, considerando que o valor de cada pixel em tons
de cinza é dado pela média aritmética de suas componentes R, G e B. (1pt)*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIN 4
#define COL 4
#define CANAL 3

#define MIN 0
#define MAX 255

int main(void) {
    int img[LIN][COL][CANAL];
    float media[3] = {0.0}; // R G B
    int brilho[LIN][COL] = {0}, maiorb[3] = {0}; // brilho, l, c
    float cinza[LIN][COL] = {0};

    srand(time(NULL));
    for(int l = 0; l < LIN; l++) {

        for (int c = 0; c < COL; c++) {
            int b = 0;

            for(int rgb = 0; rgb < CANAL; rgb++) {
                img[l][c][rgb] = MIN + (rand() % (MAX - MIN + 1));

                // media canais
                media[rgb] += img[l][c][rgb];

                // escala de cinza
                cinza[l][c] += img[l][c][rgb];

                b += img[l][c][rgb];
            }
            brilho[l][c] = b;
            cinza[l][c] /= CANAL;
        }
    }

    for(int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            printf(" (%4d %4d %4d) ", img[l][c][0],  img[l][c][1], img[l][c][2]);
        }
        printf("\n");
    }

    for(int i = 0; i < CANAL; i++)
        media[i] /= LIN * COL;

    printf("\nMEDIA CANAIS R[%3.2f], G[%3.2f], B[%3.2f]\n", media[0], media[1], media[2]);

    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            if (brilho[l][c] > maiorb[0]) {
                maiorb[0] = brilho[l][c];
                maiorb[1] = l;
                maiorb[2] = c;
            }
        }
    }
    printf("\nMAIOR BRILHO = [%d], (%d, %d)\n", maiorb[0], maiorb[1], maiorb[2]);

    printf("\nEM ESCALA DE CINZA\n");
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            printf(" %.2f\t", cinza[l][c]);
        }
        printf("\n");
    }

    return 0;
}
