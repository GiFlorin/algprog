/*Faça um programa para calcular e imprimir o salário bruto a ser recebido por um funcionário em
um mês. 
O programa deverá utilizar os seguintes dados: número de horas que o funcionário
trabalhou no mês, valor recebido por hora de trabalho e número de filhos com idade menor do
que 14 anos (para adicionar o salário família). */
#include <stdio.h>

int main() {
    // declarar
    int horas,  n_filhos;
    float valor_hora, salario;
    float sal_familia = 100;
    //comandos
    printf("N de horas trabalhadas no mes:  ");
    scanf("%d", &horas);

    printf("Quanto voce recebe por hora:  ");
    scanf("%d", &valor_hora);

    printf("Quantos filhos abaixo da idade de 14 voce tem:  ");
    scanf("%d", &n_filhos);

    salario = (horas * valor_hora) + (n_filhos * sal_familia);
    printf("O seu salario bruto e: %f", salario);

    return 0;
}
