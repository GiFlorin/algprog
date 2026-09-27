/*Uma empresa controla o estoque dos 10 produtos vendidos por ela e que est˜ao armazenados em 4 armaz´ens
atrav´es de uma matriz 10×4. Considere tamb´em que existe um vetor que cont´em o pre¸co desses 10 produtos.
0,5 pontos (a) Declare os tipos de dados, vari´aveis e constantes necess´arias para o seu programa. Inicialize a matriz de
estoque com zeros na declara¸c˜ao.
0,5 pontos (b) Ofere¸ca ao usu´ario, atrav´es de um switch sobre caracteres, as op¸c˜oes de: A) Ler Estoque, B) Maior
Estoque, C) Compras D) Custo Total e E) Sair.
0,5 pontos (c) Ler Estoque: Fa¸ca a leitura do estoque de cada produto em cada armaz´em, preenchendo a matriz de
estoque. Aproveite tamb´em para ler o pre¸co de cada produto.
0,5 pontos (d) Maior Estoque: Leia o n´umero de um produto e mostre qual o armaz´em possui o maior estoque daquele
produto.
1 ponto (e) Compras: Essa op¸c˜ao deve ler o n´umero de um armaz´em e o valor m´ınimo de estoque, e deve mostrar
quais os produtos est˜ao com estoque abaixo do valor m´ınimo.
1 ponto (f) Custo Total: Mostre o valor total dos produtos de cada armaz´em, e de toda a empresa*/
#include <stdio.h>
#define PROD 10
#define ARM 4

int main(void) {
    int estoque[ARM][PROD] = {0};
    float precos[PROD];
    char opc;
    int sair = 0;

    do {
        printf("Qual opcao voce quer? [A) Ler Estoque, B) Maior Estoque, C) Compras D) Custo Total e E) Sair] -");
        scanf(" %c", &opc);

        switch (opc) {
            case 'A':
                printf("Ler estoque\n");
                for(int i = 0; i < ARM; i++) {
                    for(int j = 0; j < PROD; j++) {
                        printf("Escreva o estoque do produto %d do armazem %d", j, i);
                        scanf("%d", &estoque[i][j]);
                    }
                }
                printf("\nLer precos\n");
                for(int i = 0; i < PROD; i++) {
                    printf("Digite o valor do produto %d: ", i);
                    scanf(" %f", &precos[i]);
                }
                break;
            case 'B':
                int p = 0, maior = 0, maior_e = 0;
                printf("Maior Estoque\n");
                printf("Qual produto voce quer saber o maior estoque: ");
                scanf("%d", &p);
                for(int i = 0; i < ARM; i++) {
                    if (estoque[i][p] > maior_e) {
                        maior_e = estoque[i][p];
                        maior = i;
                    }
                }
                printf("Maior estoque do produto %d encontrado no armazem %d [%d]\n", p, maior, maior_e);
                break;
            case 'C':
                printf("Compras\n");
                
                break;
            case 'D':
                printf("Custo total\n");
                break;
            case 'E':
                printf("SAIR\n");
                sair = 1;
                break;
        }
    } while (!sair);
    return 0;
}
