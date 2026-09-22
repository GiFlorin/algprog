/*Dados três valores, calcular e imprimir as médias aritmética e harmônica destes valores.*/

#include <stdio.h>

int main() {
    // declarar variaveis
    float num1, num2, num3;
    float media_ar, media_h;

    // comandos
    printf("Qual e o numero 1:  ");
    scanf("%d", &num1);

    printf("Qual e o numero 2:  ");
    scanf("%d", &num2);

    printf("Qual e o numero 3:  ");
    scanf("%d", &num3);

    media_ar = (num1 + num2 + num3)/3;
    media_h = 3/(1/num1 + 1/num2 + 1/num3);

    printf("A media aritmetica desses numeros e %.2f\n", media_ar);
    printf("A media harmonica desses numeros e %.2f\n", media_h);

    return 0;
};