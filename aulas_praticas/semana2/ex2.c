/*Ler distancia em km, consumo medio do carro km/l e o preco do litro do cvombustivel
calcular e imprimir a quantidade de litros necessarios e o custo total estimado da viagem, */
#include <stdio.h>

int main(void) {
    // declaracao de variaveis
    float dist, cons_medio, preco, valor_total;
    float litros_total;

    // entrada de dados
    printf("Distancia:  ");
    scanf("%f", &dist);

    printf("Consumo medio do carro(km/L):  ");
    scanf("%f", &cons_medio);

    printf("Preco do combustivel:  ");
    scanf("%f", &preco);

    // calcular
    litros_total = dist / cons_medio;
    valor_total = litros_total * preco;

    // saida de dados
    printf("\nQuantidade de litros necessarios: %.2f", litros_total);
    printf("\nCusto total da viagem:  %.2f", valor_total);

    return 0;
}
