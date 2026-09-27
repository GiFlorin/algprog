/*Escreva uma função que recebe uma palavra de até 20 caracteres e devolve
quantas letras diferentes esta palavra contém*/
#include <stdio.h>
#include <string.h>
#define TAM 20

int main(void) {
    char palavra[TAM+1];
    char letras[TAM];
    int cont_letras = 0;

    printf("Escreva uma palavra de ate %d caracteres:  ", TAM);
    fgets(palavra, TAM, stdin);

    // encontrar letras diferentes
    for (int i = 0; i < strlen(palavra); i++) // percorre as letras da palavra
    {
        int encontrou = 0;
        for (int j = 0; j <= cont_letras; j++) // percorre a lista de letras diferentes encontradas
        {
            if ((palavra[i] == letras[j]))
                encontrou = 1;
        }
        if (!encontrou && (palavra[i] != '\n') && (palavra[i] != ' ')) {
            letras[cont_letras] = palavra[i];
            cont_letras++;
        } 
    }
    printf("Letras diferentes encontradas: %d\n", cont_letras);

    // mostrar lista
    printf("Letras diferentes: ");
    for (int i = 0; i < cont_letras; i++)
    {
        printf(" [%c]", letras[i]);
    }

    return 0;
}