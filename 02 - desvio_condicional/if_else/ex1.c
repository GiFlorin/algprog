/*Fazer o algoritmo e programa C para calcular e informar as raízes de uma equação do 2º
grau. Os valores das variáveis a, b e c devem ser fornecidos via teclado*/

#include <stdio.h>
#include <math.h>

int main() {
    //definir variaveis
    int a, b, c;
    float delta, r1, r2;

    //ler a, b e c
    printf("Valor de a:  ");
    scanf("%d", &a);

    printf("Valor de b:  ");
    scanf("%d", &b);

    printf("Valor de c:  ");
    scanf("%d", &c);

    /*excecoes*/
    if (a==0) { // se a for 0, então não é uma funcao 2 grau
        printf("Não é funçao de 2 grau");
    } else {
        delta = pow(b, 2) - (4 * a * c); // calcular o delta da funcao

        if (delta < 0) { 
            printf("Raízes imaginarias!");

        } else {
            /*calcular as raizes*/
            r1 = (-1*b + sqrt(delta))/2 * a;
            r2 = (-1*b - sqrt(delta))/2 * a;
            printf("As raízes da funcao sao r1: %.1f e r2: %.1f", r1, r2);
        }
    }
}
