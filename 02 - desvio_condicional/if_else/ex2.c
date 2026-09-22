/*Faça o algoritmo e o programa C correspondente que recebe três valores reais,
diferentes entre si, e imprime os três valores em ordem crescente.*/

#include <stdio.h>

int main() {
    int a, b, c;
    int maior, meio, menor;

    //ler a, b e c
    printf("Valor de a:  ");
    scanf("%d", &a);

    printf("Valor de b:  ");
    scanf("%d", &b);

    printf("Valor de c:  ");
    scanf("%d", &c);

    // sorting
    if ((a != b) && (a != c) && (b != c)) { // checa se todos valores são diferentes
        if (a > b) {
            maior = a;
            menor = b;
        } else {
            maior = b;
            menor = a;
        }

        if (c > maior){
            meio = maior;
            maior = c;
        } else {
            if (c > menor) {
                c = meio;
            } else {
                meio = menor;
                menor = c;
            }
        }
        printf("Os valores em ordem são:  %d, %d, %d", menor, meio, maior);
    } else {
        printf("Os valores digitados não foram todos diferentes");
    }
}

