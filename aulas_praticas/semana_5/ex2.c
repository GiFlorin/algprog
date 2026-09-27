/*Escreva um programa que leia um número inteiro positivo N. O programa deve analisar todos os
números inteiros de 1 até N e determinar quantos divisores positivos cada um possui.
Ao �inal, exiba:
• o número que possui a maior quantidade de divisores;
• a quantidade de divisores desse número.
Caso haja empate, considere o menor número.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0, maior_div_num = 0, maior_div_quant = 0;
    // input
    printf("Digite o valor n: ");
    scanf("%d", &n);
    n = abs(n);

    printf("NUMEROS ATE %d\n", n);
    for(int i = 1; i <= n; i++) { // iteração por todos numeros(i) ate n
        int quant_div = 0; // quantidade de divisores por numero

        printf("Numero: %d \n", i);

        printf("Divisores: ");

        for(int div = 1; div <= i; div++){ // iteraçao por todos numeros(div) ate i/2
            if (i % div == 0) { // se i for divisivel por div
                printf(" %d", div);
                quant_div++;
            }
        }
        printf("\n");

        // atualizar as comparacoes
        if (quant_div > maior_div_quant) {
            maior_div_quant = quant_div;
            maior_div_num = i;
        }
    }
    printf("\nRESULTADOS\n");
    printf("Num maior quant divisores: %d\n", maior_div_num);
    printf("Quantidade de divisores desse num: %d\n", maior_div_quant);

}
