/*Escreva um programa na linguagem C que realize as seguintes operações:
1. Geração de Dados: O programa deve gerar um conjunto de 20 números inteiros aleatórios dentro
do intervalo fechado [-10, 10]. Armazene esses valores em um vetor principal.
2. Triagem por Sinal: A partir do vetor principal, o programa deve distribuir os números em dois novos
arranjos unidimensionais (vetores):
○ Vetor de Positivos: Contendo apenas os números maiores ou iguais a zero
○ Vetor de Negativos: Contendo apenas os números menores que zero
3. Saída de Dados:
○ O vetor original completo
○ O vetor de números positivos encontrados
○ O vetor de números negativos encontrados*/

#define MIN -10
#define MAX 10
#define TAM 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int r = 0;
    int vetor[TAM];
    int vetor_p[TAM] = {0}, tam_vp = 0;
    int vetor_n[TAM] = {0}, tam_vn = 0;

    srand(time(NULL));

    //1. Geração de Dados: O programa deve gerar um conjunto de 20 números inteiros aleatórios dentro
    // do intervalo fechado [-10, 10]. Armazene esses valores em um vetor principal.
    for (int i = 0; i < TAM; i++) {
        vetor[i] = MIN + (rand() % (MAX - MIN + 1));
        //2. Triagem por Sinal
        if (vetor[i] < 0) {
            vetor_n[tam_vn] = vetor[i];
            tam_vn++;
        } else {
            vetor_p[tam_vp] = vetor[i];
            tam_vp++;
        }
    }

    //3. Saída de Dados:
    //○ O vetor original completo
    printf("Vetor original: ["); 
    for (int i = 0; i < TAM; i++)
        printf(" %2d ", vetor[i]);
    printf("]\n");

    // ○ O vetor de números positivos encontrados
    printf("Vetor de numeros positivos: [");
    for (int i = 0; i < tam_vp; i++)
        printf(" %2d ", vetor_p[i]);
    printf("]\n");

    // ○ O vetor de números negativos encontrados
    printf("Vetor de numeros negativos: [");
    for(int i = 0; i < tam_vn; i++)
        printf(" %2d ", vetor_n[i]);
    printf("]\n");

    return 0;
}