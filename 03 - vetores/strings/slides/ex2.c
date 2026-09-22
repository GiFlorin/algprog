/*Escreva um programa que lê um texto contendo até MAXIMO caracteres,
depois lê 1 caractere e informa a primeira posição do texto onde este
caractere ocorre (ou que não existe tal caractere no texto).*/

#define MAXIMO 20
#include <stdio.h>
#include <string.h>

int main(void) {
    char texto[MAXIMO];
    char letra;

    printf("Escreva o seu texto:  "); 
    fgets(texto, MAXIMO, stdin);
    printf("texto: %s", texto);

    printf("Digite um caractere:  ");
    scanf(" %c", &letra);

    for(int i = 0; i <= strlen(texto); i++) {
        if (texto[i] == letra) {
            printf("\nO caractere [%c] foi encontrado na posicao [%d]", letra, i + 1);
            break;
        } else if (i == strlen(texto))
            printf("Nenhum caractere do texto [%s] e igual a [%c]", texto, letra);
    }

    return 0;
}
