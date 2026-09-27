/*Escreva um programa na linguagem C para identificar valores extremos (mínimos e máximos) em um arranjo
bidimensional de valores reais.
a) Ler dois números inteiros, nl (linhas) e nc (colunas). O programa deve garantir que as dimensões
estejam no intervalo [2,10] (fazer consistência)
b) Entrada de Dados: Definido o tamanho da matriz, realizar a leitura dos elementos da matriz via teclado
c) Processamento por Colunas: Identificar o maior valor de cada coluna e armazenar esses valores
em um arranjo unidimensional chamado v_maior
d) Processamento por Linhas: Identificar o menor valor de cada linha e armazenar esses valores em
um arranjo unidimensional chamado v_menor
e) Saída: Exibir a matriz original e os dois vetores resultantes para conferência.
*/
#include <stdio.h>

#define MIN 2
#define MAX 10

int main(void) {
    int nl, nc;
    int tentativas_l = 0, tentativas_c = 0;
    int matriz[MAX][MAX]; //[nl][nc]
    int v_menor[MAX], v_maior[MAX];
    //a) Ler dois números inteiros, nl (linhas) e nc (colunas). O programa deve garantir que as dimensões
    // estejam no intervalo [2,10] (fazer consistência)
    do {
        if (tentativas_l > 0)
            printf("ERRO: Apenas valores entre 2 e 10!!\n");
        printf("Escreva o numero de linhas:  ");
        scanf("%d", &nl);
        tentativas_l++;
    } while (nl < MIN || nl > MAX);

    printf("Numero de linhas = [%2d]\n", nl);
    do {
        if (tentativas_c > 0)
            printf("ERRO: Apenas valores entre 2 e 10!!");
        printf("Escreva o numero de colunas:  ");
        scanf("%d", &nc);
        tentativas_c++;
    } while (nc < MIN || nc > MAX);
    printf("Numero de colunas = [%2d]\n", nc);

    // b) Entrada de Dados: Definido o tamanho da matriz, realizar a leitura dos elementos da matriz via teclado
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            printf("Valor l[%d], c[%d]:  ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    // c) Processamento por Colunas: Identificar o maior valor de cada coluna e armazenar esses valores
    // em um arranjo unidimensional chamado v_maior
    for(int c = 0; c < nc; c++) {
        int maior = matriz[0][c];
        for(int l = 0; l < nl; l++) {
            if (matriz[l][c] > maior)
                maior = matriz[l][c];
        }
        v_maior[c] = maior;
    }

    // d) Processamento por Linhas: Identificar o menor valor de cada linha e armazenar esses valores em
    // um arranjo unidimensional chamado v_menor
    for ( int l = 0; l < nl; l++) {
        int menor = matriz[l][0];
        for(int c = 0; c < nc; c++) {
            if (matriz[l][c] > menor)
                menor = matriz[l][c];
        }
        v_menor[l] = menor;
    }

    // e) Saída: Exibir a matriz original e os dois vetores resultantes para conferência.
    printf("\n--- MATRIZ ---\n");
    for (int l = 0; l< nl; l++) {
        for (int c = 0; c < nc; c++) {
            printf(" %2d ", matriz[l][c]);
        }
        printf("\n");
    }
    printf("\n--- N_MAIOR --- \n");
    for(int i = 0; i < nc; i++){
        printf(" %2d ", v_maior[i]);
    }

    printf("\n--- N_MENOR ---\n");
    for (int i = 0; i < nl; i++) {
        printf(" %2d ", v_menor[i]);
    }
}