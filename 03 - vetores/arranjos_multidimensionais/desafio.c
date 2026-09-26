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

#define N_BOMBAS 5
#define LIN 8
#define COL 8
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
void flood_fill(int mbombas[LIN][COL], int mpedras[LIN][COL], int l, int c);

int encontrados = 0;

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

    // LOOP PRINCIPAL
    do {
        printf("\n--------------------------\n");
        int valido = 0;
        plot_board(mbombas, mpedras, mboard);

        do { // pergunta a jogada do jogador
            valido = 1;
            printf("\nEscolha um bloco (l, c):  ");
            scanf("%d %d", &jogada[0], &jogada[1]);

            // aceitar apenas posicoes validas
            if(mpedras[jogada[0]][jogada[1]] == 0) {
                printf("\n\033[1;35;40mERRO: Posicao ja escolhida!!\033[m\n");
                valido = 0;
            }
            if (jogada[0] > LIN || jogada[0] < 0 || jogada[1] > COL || jogada[1] < 0) {
                printf("\n\033[1;35;40mERRO: Escolha apenas coordenadas validas.\033[m\n");
                valido = 0;
            }
        } while(!valido);

        modo = jogar(jogada, mbombas, mpedras);
        // printf("\nEncontrados: %d / %d\n", encontrados, (LIN * COL - N_BOMBAS));
        
    } while(modo == 0);
    // FIM

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
            if (matriz[l][c] == BOMBA) // mostra itens diferentes coloridos
                printf("|\033[0;31;40m %c \033[0m", matriz[l][c]);
            else if (matriz[l][c] == PEDRA)
                printf("|\033[0;34;40m %c \033[0m", matriz[l][c]);
            else printf("|\033[0;35;40m %c \033[0m", matriz[l][c]);
        }
        printf("|\n");
    }
}

void sortear_bombas(int mbombas[LIN][COL]) { 
    for (int i = 0; i < N_BOMBAS; i++) // coloca as bombas
    {
        int c, l;
        do { // nao sroteia bombas no mesmo lugar
            c = (rand() % COL);
            l = (rand() % LIN);
            
        } while(mbombas[l][c] == -1);
        mbombas[l][c] = -1;
        // printf("\n bomba em %d %d \n", l, c);
    }

    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {

            if (mbombas[l][c] != -1) { // testa todos os quadrados em volta

                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        
                        if (((l + i >= 0) && (l+i < LIN)) && ((c+j >= 0) && (c+j < COL)))
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
        flood_fill(mbombas, mpedras, l, c);
    }
    // tira a pedra escolhida
    mpedras[l][c] = 0;  

    encontrados = 0;
    for (int l = 0; l < LIN; l++) {
        for (int c = 0; c < COL; c++) {
            if (mpedras[l][c] == 0)
                encontrados++;
        }   
    }
    
    // condicao de ganhar
    if ((encontrados == (LIN * COL - N_BOMBAS)) && resultado != -1) {
        printf("\nGANHOU!!!\n");
        resultado = 1;
    }

    return resultado;
}

void flood_fill(int mbombas[LIN][COL], int mpedras[LIN][COL], int l, int c) {
    if (mbombas[l][c] == 0)
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if (((l + i >= 0) && (l+i < LIN)) && ((c+j >= 0) && (c+j < COL)))  // TO DO: flood fill pedras (recursao?)
                    if ((mbombas[l + i][c + j] == 0) && (mpedras[l+i][c+j] != 0)) {
                        mpedras[l + i][c + j] = 0;
                        flood_fill(mbombas, mpedras, l + i, c + j);
                    }
            }
        }
}
