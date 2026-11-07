/*ENTRADA: A primeira (e única) linha de entrada contém o número inteiro w (1 ≤ w ≤ 100) — o peso da melancia comprada pelos meninos.*/
/*Imprima YES, se os meninos puderem dividir a melancia em duas partes, cada uma pesando um número par de quilos; e NO no caso contrário.*/
#include <stdio.h>

int main()
{
    int w;
    // ENTRADA
    scanf("%d", &w);

    // SAIDA
    if (w == 2)
    {
        printf("NO\n");
    }
    else
    {
        if (w % 2 == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
