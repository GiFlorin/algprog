/*ler os 3 lados e ver se é triangulo
ver o tipo de triangulo - isosceles, escaleno, equilatero*/

#include <stdio.h>

int main() {
    int l1, l2, l3;
    int is_triangulo;

    // input
    printf("lados do triangulo:  ");
    scanf("%d%d%d", &l1, &l2, &l3);

    // testar se é triangulo
    if ((l1+l2 > l3 && l2+l3 > l1 && l1+l3>l2) && (l1 != 0 && l2 != 0 && l3 != 0)) { // se lado + lado > outro lado e se nenhum e 0
        printf("\nE um triangulo valido!");
        is_triangulo = 1;
    } else {
        printf("Triangulo invalido!");
        is_triangulo = 0;
    }

    // tipo do triangulo
    if (is_triangulo) {
            if ((l1 == l2)&&(l2==l3)) // se todos lados forem iguais - equilatero
                printf("\nTipo equilatero");

            else if ((l1==l2)||(l2==l3)||(l3==l1)) // dois lados iguais - isosceles
                printf("\nTipo isosceles");

            else printf("\nTipo escaleno"); // senao (todos lados diferentes) - escaleno
    }
    return 0;
}

