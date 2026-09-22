/*Escreva um programa que lê um texto contendo até MAXIMO caracteres,
depois lê uma string com até TAMANHO caracteres, e informa a posição do
texto onde esta string ocorre (ou que não existe tal caractere no texto). 
Caso a string apareça mais de uma vez, todas as ocorrências devem ser informadas.*/

#include <stdio.h>
#include <string.h>

#define MAXIMO 30
#define TAMANHO 5

int main(void) {
    char texto[MAXIMO];
    char palavra[TAMANHO];

    printf("Escreva o texto:  ");
    fgets(texto, MAXIMO, stdin);
    printf("Escreva a palavra para achar:  ");
    fgets(palavra, TAMANHO, stdin);

    for(int i = 0; i <= strlen(texto); i++) { //itera pelas letras de [texto]
        int car_encontrados = 0;

        for(int j = 0; j <= strlen(palavra); j++) { // itera pelas letras de [palavra]

            if (palavra[j] == texto[i + j])
                car_encontrados++;
            else break;
            
            if (car_encontrados == strlen(palavra)) {
                printf("Encontrou!! a palavra [%s] no index [%d]\n", palavra, i);
            }
        }
    }

    return 0;
}