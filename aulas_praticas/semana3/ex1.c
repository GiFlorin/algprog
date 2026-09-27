/*Jogo da velha*/

#include <stdio.h>

int main() {
    // declarar variaveis
    int a, b, c, d, e, f, g, h, i;
    int ganhou = 0;

    // input valores
    printf("Valores a, b, c:  ");
    scanf("%d%d%d", &a, &b, &c);

    printf("Valores d, e, f:  ");
    scanf("%d%d%d", &d, &e, &f);

    printf("Valores g, h, i:  ");
    scanf("%d%d%d", &g, &h, &i);

    // printar jogo
    printf(" %d %d %d \n %d %d %d \n %d %d %d", a, b, c, d, e, f, g, h, i);

    // checar se ganhou
    if ((a && b && c) || (d && e && f) || (g && h && i))  // horizontais
        ganhou = 1;

    else if ((a && d && g) || (b && e && h) || (c && f && i))  // verticais
        ganhou = 1;

    else if ((a && e && i) || (g && e && c))  // diagonais
        ganhou = 1;

    // mostrar resultado
    if (ganhou)
        printf("\nGanhou!");
    else
        printf("\nPerdeu!  ");

    return 0;
}
