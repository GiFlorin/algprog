/*Escreva um programa na linguagem C que realize as seguintes operações:
1. Geração de Dados: O programa deve gerar automaticamente um conjunto de 20 números inteiros
aleatórios. Esses números devem obrigatoriamente estar dentro do intervalo fechado [1, 50].
Armazene esses valores em um vetor principal
2. Cálculo da Média: Calcule a média aritmética simples de todos os 20 números gerados
3. Filtragem (Separação): A partir do vetor principal, o programa deve construir outros dois arranjos
unidimensionais (vetores)
○ Vetor Maiores: Contendo apenas os números que são maiores que a média calculada.
○ Vetor Menores: Contendo os números que são menores ou iguais à média calculada.
4. Saída de Dados: Ao final da execução, o programa deve exibir de forma organizada:
○ O vetor original com os 20 números.
○ O valor da média calculada
○ Os elementos do Vetor Maiores (maiores que à média).
○ Os elementos do Vetor Menores (menores ou iguais à média).*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50
#define MIN 1
#define TAM 20

int main(void) {
    int nums[TAM] = {0};
    float media = 0;
    int menores[TAM] = {0}, maiores[TAM] = {0}, menor_i = 0, maior_i = 0;
    srand(time(NULL));
    printf("NUMEROS SORTEADOS\n");
    
    // 1. Geração de Dados
    for (int i = 0; i< TAM; i++){
        nums[i] = MIN + (rand() % (MAX - MIN + 1)); // gera um numero entre min e max
        media += nums[i]; // 2. Media - faz a somatoria da media
        printf(" %2d ", nums[i]); // 4. imprimir vetor sorteado
    }
    media /= TAM; // divide a media
    printf("\nMedia: %.2f\n", media); // 4. imprimir media
    // 3. Filtragem (Separação)
    for (int i = 0; i < TAM; i++) {
        if (nums[i] > media) {
            maiores[maior_i] = nums[i];
            maior_i++;
        } else {
            menores[menor_i] = nums[i];
            menor_i++;
        }
    }
    // 4. saida de dados
    printf("\nNUMEROS MAIORES\n");
    for (int i = 0; i < maior_i; i++) {
        printf(" %2d ", maiores[i]);
    }
    printf("\nNUMEROS MENORES\n");
    for (int i = 0; i < menor_i; i++) {
        printf(" %2d ", menores[i]);
    }

    return 0;
}