/*Dado o preço de um produto em reais, converter este valor para o equivalente em dólares. O
programa deverá ler o preço e a taxa de conversão para o dólar. */

#include <stdio.h>

int main() {
    // declarar variáveis
    float valor, taxa_dolar, dolares;

    //comandos
    printf("Qual e o valor:  ");
    scanf("%f", &valor);

    printf("Qual a taxa de conversao para dolar:  ");
    scanf("%f", &taxa_dolar);

    dolares = valor * taxa_dolar;
    printf("O valor %.2f reais corresponde a %.2f dolares", valor, dolares);

    return 0;
}
