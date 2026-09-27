/*Fa¸ca um programa que leia uma string contendo uma frase de at´e 300 caracteres e em seguida conte e escreva
o n´umero de palavras contidas naquela frase. Considere que as palavras est˜ao separadas por espa¸cos em
branco. Considere tamb´em que a frase nunca inicia ou termina com um espa¸co em branco. Por exemplo,
para a entrada “O rato roeu a roupa do rei de Roma”, seu programa deve apresentar como sa´ıda o valor 9.*/
#include <stdio.h>
#include <string.h>

#define TAM 300

int main(void) {
    char string[TAM + 1];
    int n_pal = 0; // contador de palavras

    printf("Escreva o seu texto:  ");
    fgets(string, TAM, stdin);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' '|| string[i] == '\n' || string[i] == '\0') {
            n_pal++;
        }
    }
    printf("O numero de palavras e %d", n_pal);

    return 0;
}
