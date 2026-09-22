/*Dada uma matriz m (10, 20), preenchê-la por leitura e imprimir:
a) o maior elemento de cada linha da matriz;
b) a média dos elementos de cada coluna;
c) o produto de todos os elementos diferentes de zero;
d) quantos elementos são negativos;
e) posição ocupada (linha-coluna) por um elemento cujo valor será lido pelo programa*/

/*EXPLICACAO: eu não queria preencher os valores da matriz todas vezes, entao fiz ela também preencher 
por numeros aleatorios quando eu quiser, mas o exercicio não pede isso*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 20
#define LIN 10
#define RAND 1 //se é aleatorio ou nao (para teste) {0 - entrada manual; 1 - numeros aleatorios}
#define MIN -5
#define MAX 5

int main(void) {
    int matriz[COL][LIN];
    float media[COL] = {0};
    int cont_n = 0, maior[LIN] = {MIN}, procurar;
    double produto = 1.0; 
    srand(time(NULL));

    // preenchê-la por leitura
    printf("\n --- ENTRADA DE VALORES ---\n");
    for (int l = 0; l < LIN; l++) {
        for(int c = 0; c < COL; c++) {
            // entrada de dados
            if (RAND == 0) { // preencher manualmente
                int tentv = 0;
                do {
                    if (tentv > 0)
                        printf("ERRO: Apenas valores entre [%d] e [%d]\n", MIN, MAX);
                    printf("Digite o valor [%d][%d]:  ", c, l);
                    scanf("%d", &matriz[c][l]);
                    tentv++;
                } while(matriz[c][l] < MIN || matriz[c][l] > MAX); // so vai deixar valores entre MIN e MAX
                

            } else { // nao quero preencher todos numeros todas vezes
                matriz[c][l] = MIN + (rand() % (MAX - MIN + 1));
            }
            
            //processamento
            if (matriz[c][l] > maior[l]) // a) maior de cada linha
                maior[l] = matriz[c][l];

            media[c] += matriz[c][l]; // b) somatoria media

            if (matriz[c][l] != 0) { // c) produto dos diferentes de 0
                produto *= matriz[c][l];
                // printf("produto %d = %e\n", matriz[c][l], produto);
            }

            if (matriz[c][l] < 0) // d) conta os negativos
                cont_n++;
        }
    }

    /* ---- SAIDA DE DADOS ---- */
    printf("\n--- MATRIZ ---\n");
    for (int l = 0; l < LIN; l++){
        for (int c = 0; c < COL; c++){
            printf("%3d ", matriz[c][l]);
        }
        printf("\n");
    }

    printf("\nA) MAIOR DE CADA LINHA\n");
    for (int i = 0; i < LIN; i++) 
        printf("[%2d] = %2d\n", i, maior[i]);
    
    printf("\nB) MEDIA DE CADA COLUNA\n");
    for (int i = 0; i < COL; i++) {
        media[i] /= LIN; // divide a somatoria da media de cada linha
        printf("Media col[%2d] = %3.2f\n", i, media[i]);
    }
    printf("\nC) PRODUTO = [%e]\n", produto);
    printf("D) NUMEROS NEGATIVOS = [%2d]\n", cont_n);

    /* ---- e) posição ocupada (linha-coluna) por um elemento cujo valor será lido pelo programa -----*/
    int tentp = 0;

    do { // perguntar o valor (apenas valores validos)
        if (tentp > 0)
            printf("ERRO: Apenas valores entre [%d] e [%d]\n", MIN, MAX);
        printf("\nQual valor voce quer procurar?  ");
        scanf("%d", &procurar);
        tentp++;
    } while (procurar < MIN || procurar > MAX);

    // procurar o valor
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            if (matriz[c][l] == procurar ) 
                printf("Valor %d encontrado em {%d , %d}\n", procurar, c, l);
        }
    }
    
    return 0;
}
