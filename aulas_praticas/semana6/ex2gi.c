/*Escreva um programa em que gere aleatoriamente 20 números inteiros entre 1 e 10 (inclusive),
armazenando-os em um vetor unidimensional e imprimindo o vetor gerado (1.5pts).
Em seguida, o programa deve calcular e informar:
a) a frequência absoluta de cada número distinto presente no vetor (2pts)
b) a média aritmética dos 20 números gerados (0.5pts)
c) os números armazenados no vetor que sejam maiores que a média, na ordem em que aparecem e mantendo as
repetições (1pt).*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 1
#define MAX 10
#define TAM 20

int main(void) {
    int vetor[TAM] = {0};
    int vetorf[MAX] = {0};
    float somatoria = 0;

    srand(time(NULL));
    printf("\nVETOR\n");

    for(int i = 0; i < TAM; i++) {
        vetor[i] = MIN + (rand() % (MAX - MIN + 1));
        vetorf[vetor[i]-1]++;
        somatoria += vetor[i];
        printf(" %d ", vetor[i]);
    }
    // frequencia
    for(int i = 0; i < 10; i++) {
        printf("\nFrequencia de [%d] = [%d]", i+1, vetorf[i]);
    }

    // acima da media
    somatoria /= TAM;
    printf("\nMEDIA: %.2f\n", somatoria);
    printf("\n NUMEROS ACIMA DA MEDIA \n");
    for (int i = 0; i<TAM; i++) {
            if(vetor[i] > somatoria)
                printf(" %d ", vetor[i]);
    }

}
