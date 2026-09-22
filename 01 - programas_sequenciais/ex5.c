/*[Algoritmos - A. I. Orth] Escrever um algoritmo que lê o código da peça 1, o número de peças 1,
o valor unitário da peça 1, o código da peça 2, o número de peças 2, o valor unitário da peça 2 e
a percentagem de IPI a ser acrescentado e calcula o valor total a ser pago. 
*/

#include <stdio.h>

int main() {
    // declarar variaveis
    int peca_1[3];
    int peca_2[3];
    float ipi, preco;

    // comandos
    // peca 1
    printf("Codigo 1:  ");
    scanf("%d", &peca_1[0]);

    printf("Numero 1:  ");
    scanf("%d", &peca_1[1]);

    printf("valor 1:  ");
    scanf("%d", &peca_1[2]);

    // peca 2
    printf("Codigo 2:  ");
    scanf("%d", &peca_2[0]);

    printf("Numero 2:  ");
    scanf("%d", &peca_2[1]);

    printf("valor 2:  ");
    scanf("%d", &peca_2[2]);

    printf("Porcentagem ipi:  ");
    scanf("%f", &ipi);

    preco = peca_1[1] * peca_1[2] + peca_2[1] * peca_2[2];
    preco += preco * (ipi/100);

    printf("O valor final ficou: %f", preco);
    
    return 0;
}
