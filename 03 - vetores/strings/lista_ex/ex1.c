/*Faça um programa que recebe um texto de até 40 caracteres e gera, em um vetor, a
distribuição de freqüência de comprimento de palavras. Considere que no texto
podem aparecer palavras de até 10 caracteres. 
As palavras podem estar separadas por espaços em branco ou pelos caracteres vírgula e ponto. 
O final do texto é sinalizado pelo caracter #*/
#include <stdio.h>
#include <string.h>

#define TAM 40

int main(void) {
    char texto[TAM+1];
    int fim_texto = 0;
    int comp_p[11]= {0}, i = 0;

    printf("\033[1;30;42mEscreva o seu texto[40]:\033[m  ");
    fgets(texto, TAM+1, stdin);

    while(!fim_texto) 
    {
        int c = 0;
        int fim_p = 0;

        while(!fim_p) 
        {
            if(texto[i] == ' ' || texto[i] == ';') 
            {
                fim_p = 1;
                comp_p[c]++;
            } else if(texto[i] == '#'|| texto[i] == '\0')
            {
                fim_p = 1;
                fim_texto = 1;
                comp_p[c]++;
            } else 
            {
                c++;
            }
            i++;
        }
    }
    printf("\n%s", texto);
    printf("\033[1;33;40m\n---- FREQUENCIA PALAVRAS ----\033[m\n");
    for (int i = 0; i < 10; i++)
        printf("%2d | %2d\n", i, comp_p[i]);

    return 0;
}