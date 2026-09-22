/*Escreva um programa que leia dois números inteiros do teclado e imprima a soma, 
a subtração e a multiplicação entre eles.*/
#include <stdio.h>

int main() {
    int a, b;
    printf("Digite o primeiro numero: ");
    scanf("%i", &a);

    printf("Digite o segundo numero: ");
    scanf("%i", &b);

    printf("A soma entre %i e %i = %i\n", a, b, a+b);
    printf("A subtracao %i - %i = %i\n", a, b, a-b);
    printf("A multiplicacao %i * %i = %i\n", a, b, a*b);
}
