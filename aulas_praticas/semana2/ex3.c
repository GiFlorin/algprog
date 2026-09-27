/*Receber valor inicial de uma divida, taxa de juros mensal, quantidade de meses atrasada
calcular valor atualizado usando juros simples e compostos*/
#include <stdio.h>
#include <math.h>

int main(void){
    float valor_inicial, juros, atraso;
    float juros_composto, juros_simples;

    printf("Valor inicial da dívida:  ");
    scanf("%f", valor_inicial);

    printf("Taxa de juros mensal:  ");
    scanf("%f", juros);

    printf("Quantidade de meses atrasada:  ");
    scanf("%f", atraso);

    juros_composto = valor_inicial * pow((1 + (juros/100.0)), atraso);
    juros_simples = valor_inicial * (1 + atraso *(juros/100));

    printf("Juros simples: %.2f", juros_simples);
    printf("Juros compostos: %.2f", juros_composto);

    return 0;
}
/*Receber valor inicial de uma divida, taxa de juros mensal, quantidade de meses atrasada
calcular valor atualizado usando juros simples e compostos*/
#include <stdio.h>
#include <math.h>

int main(){
    // declaracao variaveis
    float valor_inicial, juros, atraso;
    float juros_composto, juros_simples;

    // entrada de dados
    printf("Valor inicial da dívida:  ");
    scanf("%f", &valor_inicial);

    printf("Taxa de juros mensal:  ");
    scanf("%f", &juros);

    printf("Quantidade de meses atrasada:  ");
    scanf("%f", &atraso);

    //calculo
    juros_composto = valor_inicial * pow((1 + (juros/100.0)), atraso);
    juros_simples = valor_inicial * (1 + atraso *(juros/100));

    // saida de dados
    printf("\nJuros simples: %.2f", juros_simples);
    printf("\nJuros compostos: %.2f", juros_composto);

    return 0;
}
