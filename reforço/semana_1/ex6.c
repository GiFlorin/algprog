/*Escreva um programa que leia três números inteiros e calcule sua média aritmética, 
imprimindo o resultado com duas casas decimais. Tome cuidado para o resultado não ser 
truncado por uma divisão inteira.*/
#include <stdio.h>

int main() {
    int a, b, c;
    float media;
    printf("a =  ");
    scanf("%i", &a);

    printf("b =  ");
    scanf("%i", &b);

    printf("c =  ");
    scanf("%i", &c);

    media = (a+b+c)/3.0;
    printf("A media é: %.2f\n", media);
}