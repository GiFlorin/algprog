/*Uma matriz esparsa é uma matriz que tem aproximadamente 2/3 de seus elementos iguais a zero. Fazer
um programa que lê uma matriz esparsa me(10,10) e forma uma matriz condensada mc, de apenas três
colunas, com os elementos não nulos de me, de forma que:
a) a primeira coluna contém os valores não nulos de me;
b) a segunda coluna contém a linha de me onde foi encontrado este valor; e
c) a terceira coluna contém a coluna de me onde foi encontrado este valor.
Imprimir as duas matrizes. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COL 10
#define LIN 10
#define MIN 1
#define MAX 10

int main(void) {
    int me[LIN][COL], matriz_p[LIN][COL], mc[(LIN * COL / 2)][3] = {0}; // mc tem de espaço metade de me(margem de erro)
    int i_mc = 0; // i_mc = indice matriz compacta
    srand(time(NULL));

    // preencher matriz_p e me
    printf("\n ---- MATRIZ ESPARSA ---- \n");
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            matriz_p[l][c] = (rand() % 3) % 2; // matriz pesos: gera 0 2/3 das vezes
            me[l][c] = (MIN + (rand() % (MAX - MIN + 1))) * matriz_p[l][c]; // gera um número e multiplica com o peso
            printf(" %2d", me[l][c]);
        }
        printf("\n");
    }
        
    printf("\n ---- MATRIZ COMPACTA ---- \n");
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            // formar mc
            if (me[l][c] != 0) { // valores nao nulos
                mc[i_mc][0] = me[l][c]; // a)
                mc[i_mc][1] = l; // b)
                mc[i_mc][2] = c; // c)

                printf(" %2d [%2d] [%2d]\n", mc[i_mc][0], mc[i_mc][1], mc[i_mc][2]);
                i_mc++;
            }
        }
    }
    return 0;
}
