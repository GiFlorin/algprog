/*Escreva um programa que leia o preço de um produto (float) e a quantidade comprada (int), 
e imprima o valor total da compra, com duas casas decimais.*/
#include <stdio.h>

int main() {
    float valor;
    int quant;
    printf("Preco do produto: ");
    scanf("%f", &valor);

    printf("Quantidade: ");
    scanf("%i", &quant);

    printf("Valor total = %.2f", valor*quant);
}
