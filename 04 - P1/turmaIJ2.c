/*Escreva um programa em C para processar as notas do quesito BATERIA de 5
escolas de samba do Carnaval. 
Para cada escola, leia 4 notas (valores reais)
atribuídas pelos jurados (fazer consistência que as notas estão no intervalo [7,10]) e armazenar num array bidimensional. 
Use defines para o número de notas e jurados.
O cálculo da nota final da bateria para cada escola de samba deve seguir a
regra de descarte: identifique a menor nota recebida entre os 4 jurados e
calcule a média aritmética simples das outras 3 notas.
Saída: O programa deve exibir para cada escola a respectiva média final*/

#define N_ESCOLAS 5
#define N_JURADOS 4
#define MIN_NOTA 7.0
#define MAX_NOTA 10.0

#include <stdio.h>

int main(void) {
    // declaracao variaveis
    float notas[N_ESCOLAS][N_JURADOS] = {0};
    float medias[N_ESCOLAS] = {0};

    // entrada de dados
    for (int e = 0; e < N_ESCOLAS; e++) { // itera pelo numero de escolas
        printf("\n--- ESCOLA %d ---\n", e+1);

        for (int j = 0; j < N_JURADOS; j++) { // itera pelo numero de jurados
            int tentativas = 0;
            do {
                if (tentativas > 0)
                    printf("Apenas notas entre %.1f e %.1f!!\n", MIN_NOTA, MAX_NOTA);
                printf("  Jurado %d: ", j+1);
                scanf("%f", &notas[e][j]);
                tentativas++;
            } while ((notas[e][j] > MAX_NOTA) || (notas[e][j] < MIN_NOTA));
        }
    }
    printf("\n--- MEDIAS FINAIS ---\n");

    // regra de descarte & calculo de medias
    for (int e = 0; e < N_ESCOLAS; e++) {
        float menor = MAX_NOTA;
        for (int j = 0; j < N_JURADOS; j++) { // encontra a menor nota
            medias[e] += notas[e][j];
            if (notas[e][j] < menor)
                menor = notas[e][j];
        }
        medias[e] -= menor; // tira a menor
        medias[e] /= N_JURADOS - 1; // divide a media
        printf("Media escola %2d: %.2f\n", e, medias[e]);
    }

    return 0;
}
