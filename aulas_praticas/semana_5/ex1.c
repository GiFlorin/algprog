/*Implemente um programa que peça ao usuário para adivinhar um número inteiro secreto entre 0 e 100.
Seu programa deverá fornecer dicas se o número fornecido pelo usuário é maior ou menor do que o número a
ser adivinhado.
Caso o número seja igual ao número secreto, o programa deverá apresentar a mensagem
“Numero correto!”.
Caso contrário, deverá informar “Numero secreto eh maior.” ou ”Numero secreto eh menor.”.
Após 5 tentativas, o programa deve informar ao usuário a dica adicional se o número secreto é par ou ı́mpar, além
de ser maior ou menor.
Obs.: use #de�ine para de�inir um número secreto.*/

#define SECRETO 43
#include <stdio.h>

int main(void) {
    int palpite, correto = 0, cont = 0;
    printf("Adivinhe um número inteiro secreto entre 0 e 100\n.");

    do {
        cont++;
        printf("\nDigite o seu palpite:");
        scanf("%d", &palpite);

        // checar se e correto
        if (palpite == SECRETO) {
            correto = 1;
            printf("Numero correto!\n");

        // dicas
        } else {
            if (palpite > SECRETO)
                printf("O numero secreto e menor\n");
            else if (palpite < SECRETO)
                printf("O numero secreto e maior\n");

            // DICA ADICIONAL
            if (cont >= 5) {
                if (SECRETO % 2 == 0)
                    printf("Dica adicional: o numero secreto e par\n");
                else printf("Dica adicional: o numero secreto e impar\n");
            }
        }
    } while(!correto);
}
