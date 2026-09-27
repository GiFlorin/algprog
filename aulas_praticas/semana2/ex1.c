/*Ler o preço de um produto e um percentual de desconto
Calcular e imprimir o valor do desconto e o preço final do produto*/
#include <stdio.h>

int main(void) {
    // declarar variaveis
    float preco, valor_final, valor_desconto;
    int percentual;

    // entrada de dados
    printf("Preco do produto:  ");
    scanf("%f", &preco);

    printf("Percentual de desconto:  ");
    scanf("%d", &percentual);

    // calculos
    valor_desconto = preco * percentual / 100.0; // calcular valor do desconto
    valor_final = preco - valor_desconto; // calcular valor final

    // saida de dados
    printf("Valor do desconto: %.2f\n", valor_desconto);
    printf("Valor final: %.2f", valor_final);
    return 0;
}
