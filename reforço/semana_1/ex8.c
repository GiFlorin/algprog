/*Escreva um programa que leia um valor em reais (float) e simule um "trocador de moedas": 
calcule quantas notas de 100, 50, 20, 10, 5 e 1 real são necessárias para compor esse valor, 
utilizando o menor número possível de notas em cada etapa (dica: utilize divisão inteira e módulo repetidamente, 
e converta a parte decimal para inteiro no início).*/
#include <stdio.h>

int main() {
    float valor;
    int cem, cinquenta, vinte, dez, cinco, um;
    printf("Qual o valor:  ");
    scanf("%f", &valor);
    int(valor);

    cem = valor/100;
    valor %= 100;
    cinquenta = valor/50;
    valor %= 50;
    vinte
}