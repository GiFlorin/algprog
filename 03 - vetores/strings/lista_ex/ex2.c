/*Dado um texto, identificar cada palavra deste texto e verificar se é palíndroma.
Uma palavra palíndroma é aquela que apresenta a mesma grafia quando lida a partir
do início ou de trás para diante; exemplo: RIR, SOLOS, ASA, RALAR, AMA. 
O programa deve utilizar uma função booleana para verificar se uma palavra
identificada no texto é palíndroma. A saída do programa deve ser uma tabela listando
as palavras identificadas e, para cada uma, a mensagem dizendo se é ou não
palíndroma*/
#include <stdio.h>
#include <string.h>

#define TAM 20

int is_palindroma(char palavra[TAM]); // verifica se a palavra é palindroma

int main(void) {
    char texto[TAM];
    int c = 0, f = 0; // auxiliares - indice do começo e fim das palavras

    printf("Digite o seu texto:  ");
    fgets(texto, TAM, stdin);

    // identificar palavras
    for (int i = 0; i < strlen(texto)+1; i++)
    {
        if (texto[i] == ' ' || texto[i] == '\0') { // se a palavra acabou

            char palavra[TAM] = {0};
            for (int j = c, k = 0; j < i; j++, k++) // faz um vetor só com a palavra
                palavra[k] = texto[j];
            is_palindroma(palavra);
            c = i + 1;
        }
    }

    return 0;
}

int is_palindroma(char palavra[TAM]) { 
    // retorna 1 se a palavra[TAM] e palindroma e 0 se não e printa o resultado
    // recebe um vetor só com a palavra
    int igual = 1;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] != palavra[strlen(palavra) - i - 1]) 
            igual = 0;
    }
    if (igual)
        printf("%s e um palindromo!!\n");
    else
        printf("%s nao e um palindromo :(\n", palavra);
}
