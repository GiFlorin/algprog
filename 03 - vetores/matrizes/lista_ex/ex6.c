/*Preencher por leitura uma matriz m (5,5). Em seguida, calcular e imprimir a média dos elementos das
áreas assinaladas: */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM 5
#define N_MASKS 6
#define MIN 0
#define MAX 10

float med_n(); // multiplicação elemento a elemento de matrizes & media dos elementos nao nulos de uma matriz
void escreve_matriz(); // print matriz

int main(void) {
    // mascaras dos valores 
    int matriz[TAM][TAM] = {0};
    srand(time(NULL));
    const int masks[N_MASKS][TAM][TAM] = {{
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    }, {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1}
    }, {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    }, {
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    }, {
        {1, 1, 1, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }, {
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0}
    } };

    // gerar os numeros da matriz
    printf("\n \033[1;35;40m---- MATRIZ GERADA ----\033[m \n");
    for (int l = 0; l < TAM; l++) {
        for (int c = 0; c < TAM; c++)
            matriz[l][c] = MIN + (rand() % (MAX - MIN + 1));
    }
    
    escreve_matriz(matriz);

    for (int i = 0; i < N_MASKS; i++)
    {
        printf("\n\033[1;33;40m---- MASCARA %d ----\033[m\n", i+1);
        escreve_matriz(masks[i]);
        printf("Media: %.2f\n", med_n(matriz, masks[i]));
    }
    
    
    return 0;
}

float med_n(int m1[TAM][TAM], int m2[TAM][TAM]) {
    int val = 0; // contador de valores nao nulos
    float somatoria = 0;

    for (int l = 0; l < TAM; l++)
    {
        for (int c = 0; c < TAM; c++)
        {
            if(m1[l][c] * m2[l][c] != 0) {
                somatoria += m1[l][c] * m2[l][c];
            }
            if(m2[l][c] != 0) // se o valor da mascara nn for 0
                val++;
        }
    }
    somatoria /= val;
    return somatoria;
}

void escreve_matriz(int m[TAM][TAM]) { // print matriz
    for (int l = 0; l < TAM; l++)
    {
        for (int c = 0; c < TAM; c++)
        {
            printf(" %2d ", m[l][c]);
        }
        printf("\n");
    }
} 

