/*[Algoritmos - D. D. Salvetti & L. M. Barbosa] Eliminar, de uma cadeia de
caracteres, todas as ocorrências de excesso de brancos. Entende-se por excesso de
brancos a ocorrência de mais de um branco entre duas palavras ou a ocorrência de
pelo menos um branco no início ou no fim da cadeia. */
#include <stdio.h>
#include <string.h>

#define TAM 40

int main(void) {
    char string[TAM] = {0};
    char saida[TAM] = {0};
    int cont_b = 1;
    int i_s = 0; // indice string saida
    int i_c = 0, i_f = 0; // indice do fime comeco da palavra

    printf("Digite a sua string:  ");
    fgets(string, TAM, stdin);

    // tirar os espaços no começo
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
            i_c++;
        else break;
    }

    // tirar os espaços no fim
    i_f = strlen(string);
    for (int i = strlen(string)-1; i >= 0; i--)
    {
        if (string[i] == ' ' || string[i] == '\n')
            i_f--;
        else break;
    }
    
    // tirar os espaçoes no meio
    for (int i = i_c; i < i_f; i++)
    {
        if (string[i] == ' ')
            cont_b++;
        else cont_b = 0;

        if ((cont_b < 2) && (string[i]) != '\n') {
            saida[i_s] = string[i];
            i_s++;
        }
    }
    // saida de dados
    printf("\n---------------------\n");
    printf("Entrada: [%s]\n", string);
    printf("Tamanho entrada = %d\n", strlen(string));
    printf("Saida: [%s]\n", saida);
    printf("Tamanho saida = %d\n", strlen(saida));
    return 0;
}