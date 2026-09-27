/*Escreva uma função que recebe uma string de até 80 caracteres e um determinado
caracter e devolve a localização da última ocorrência deste caracter na string. Se o
caracter não aparecer na string, devolver um valor negativo. */
#include <stdio.h>
#include <string.h>
#define TAM 80

int main(void) {
    char string[TAM] = {0};
    char letra;
    int achou = 0;

    printf("Digite a sua string: ");
    fgets(string, TAM, stdin);
    printf("Digite o caractere:  ");
    scanf(" %c", &letra);

    for (int i = strlen(string); i >= 0; i--) // percorre a string de tras para frente
    {
        if (string[i] == letra) {
            printf("Letra %c encontrada no indice %d\n", letra, i);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("Letra nao encontrada na string [%d]\n", -1);
}
