/*. (5pts) Escreva um programa que leia os elementos de uma matriz M de inteiros de dimensão 4 × 4.
O programa deve:
a) Calcular e imprimir a soma dos elementos de cada linha da matriz, indicando o número da linha
correspondente. (1.5pts)
b) Calcular e imprimir a soma dos elementos da diagonal principal. (1.5pts)
c) Substituir todos os elementos maiores que 10 pelo valor 10. (1pt)
d) Imprimir a matriz resultante em formato tabular. (1pt)
Atenção: para resolver “a” e “b” é obrigatório a utilização de uma estrutura de repetição que considere
o tamanho da matriz, sem escrever individualmente os índices dos elementos a serem somados*/

#include <stdio.h>
#define TAM 4

int main(void) {
    int matriz[TAM][TAM] = {0};
    int somad = 0;

    // ler elementos matriz
    for (int l = 0; l < TAM; l++) {
        for (int c = 0; c < TAM; c++) {
            printf("Digite valor (%d, %d):  ", l, c);
            scanf(" %d", &matriz[l][c]);
        }
    }

    for (int l = 0; l < TAM; l++) { // imprimir matriz
        for (int c = 0; c < TAM; c++) {
            printf(" %d", matriz[l][c]);
        }
        printf("\n");
    }

    for (int l = 0; l < TAM; l++) { // somar e imprimir soma de cada linha
        int soma = 0;
        for (int c = 0; c < TAM; c++) {
            soma += matriz[l][c];

            if (l == c) // soma da diagonal principal
                somad += matriz[l][c];
        }
        printf("Linha [%2d] soma = [%2d]\n", l+1, soma);
    }
    printf("Soma da diagonal principal: %2d\n", somad);

    printf("\n--- MATRIZ SUBSTITUIDA ---\n");
    for(int l = 0; l < TAM; l++) { // substituir valores > 10 por 10 e imprimir matriz
        for (int c = 0; c < TAM; c++) {
            if (matriz[l][c] > 10)
                matriz[l][c] = 10;
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }

    return 0;
}
