/*Faça um programa para simular o jogo campo minado.
Inicialmente, distribua em posições aleatórias, uma quantidade
específica bombas.
Em seguida, para todas as posições onde não existem bombas,
defina a quantidade de vizinhos (norte, sul, leste, oeste) com
bombas.
Após a inicialização da matriz, o jogo inicia. As posições devem
estar reveladas ou não. 
A cada jogada, o usuário escolhe uma coordenada e o programa revela aquela posição. 
Se for uma bomba, o jogo encerra.
Se não for uma bomba, revela os espaços livres de bombas no
entorno.*/

#define N_BOMBAS 10
#define LIN 9
#define COL 9
#define PEDRA '#'
#define BOMBA '@'

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// PROTOTIPOS FUNCOES
void encher_matriz(int matriz[LIN][COL], int item); // enche matriz com int
void printm(char matriz[LIN][COL]); // imprime o tabuleiro, matriz de char
void plot_board(int mbombas[LIN][COL], int mpedras[LIN][COL], char mboard[LIN][COL]); // mistura mbombas, mpedras para fazer o tabuleiro
int jogar(int jogada[2], int mbombas[LIN][COL], int mpedras[LIN][COL]); // valida jogada, atualiza o modo e mpedras
void sortear_bombas(int mbombas[LIN][COL]); // sorteia as posiçoes das bombas no tabuleiro

int main(void) {
    int mbombas[LIN][COL] = {0};
    int mpedras[LIN][COL] = {0};
    char mboard[LIN][COL];
    int modo = 0; // -1 perdeu, 0 jogando, 1 ganhou
    int jogada[2] = {0};

    srand(time(NULL));
    encher_matriz(mbombas, 0);
    encher_matriz(mpedras, 1);
    sortear_bombas(mbombas);

    do {
        int tentc = 0;
        plot_board(mbombas, mpedras, mboard);

        do { // pergunta a jogada do jogador
            if (tentc > 0) printf("\nERRO: Escolha apenas coordenadas validas.\n");
            printf("\nEscolha um bloco (l, c):  ");
            scanf("%d %d", &jogada[0], &jogada[1]);
            // TO DO: nao deixar jogador escolher pedra ja sumida
            tentc++;
        } while(jogada[0] > LIN || jogada[0] < 0 || jogada[1] > COL || jogada[1] < 0);

        modo = jogar(jogada, mbombas, mpedras);
        
    } while(modo == 0);

    return 0;
}

void encher_matriz(int matriz[LIN][COL], int item) { // encher a matriz com um int
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) 
            matriz[l][c] = item;
    }
}

void printm(char matriz[LIN][COL]) { // printar o jogo
    printf("  ");
    for (int i = 0; i < COL; i++) // linha indices de cima
        printf("  %d ", i);
    printf("\n");

    for (int l = 0; l < LIN; l++) {
        printf("%d ", l); // indices ao lado

        for (int c = 0; c < COL; c++) {
            if (matriz[l][c] == BOMBA) // mostra a bomba vermelha
                printf("|\033[0;31;40m %c \033[0m", matriz[l][c]);
            else if (matriz[l][c] == PEDRA)
                printf("|\033[0;34;40m %c \033[0m", matriz[l][c]);
            else printf("|\033[0;35;40m %c \033[0m", matriz[l][c]);
        }
        printf("|\n");
    }
}

void sortear_bombas(int mbombas[LIN][COL]) { // TO DO: ainda pode sortear bombas no mesmo lugar
    for (int i = 0; i < N_BOMBAS; i++) // coloca as bombas
    {
        int c = (rand() % (COL + 1));
        int l = (rand() % (LIN + 1));
        mbombas[l][c] = -1;
    }

    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {

            if (mbombas[l][c] != -1) { // testa todos os quadrados em volta

                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {

                        if (mbombas[l + i][c + j] == -1)
                            mbombas[l][c]++;
                    }
                }
            }
        }   
    }
}

void plot_board(int mbombas[LIN][COL], int mpedras[LIN][COL], char mboard[LIN][COL]) {
    for (int l = 0; l < LIN; l++) {

        for (int c = 0; c < COL; c++) {  // escreve o mboard com base em mbombas e mpedras

            if (mpedras[l][c] == 1)
                mboard[l][c] = PEDRA;

            else {
                if (mbombas[l][c] == -1)
                    mboard[l][c] = BOMBA;

                else if (mbombas[l][c] == 0)
                    mboard[l][c] = ' ';

                else 
                    mboard[l][c] = mbombas[l][c] + '0'; // conversao digito numerico para caractere
            }
        }
    }
    printm(mboard);
}

int jogar(int jogada[2], int mbombas[LIN][COL], int mpedras[LIN][COL]) {
    // valida a jogada, pedra escolhida desaparece
    int l = jogada[0];
    int c = jogada[1];
    int resultado = 0;
    if (mbombas[l][c] == -1) {
        //perdeu
        printf("\n PERDEU!! \n");
        resultado = -1;
    }   
    else {
        // checar as pedras ao redor
        if (mbombas[l][c] == 0)
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if (mbombas[l + i][c + j] == 0 && ((l + i >= 0) && (l+i < LIN)) && ((c+1 >= 0) && (c+i < COL)))  // TO DO: consertar bordas
                        mpedras[l + i][c + j] = 0;
                }
            }
    }
    // tira a pedra escolhida
    mpedras[l][c] = 0;  
    return resultado;
}
