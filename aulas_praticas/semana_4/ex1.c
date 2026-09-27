/*Ler um valor inteiro n >=0
s1 = 0 + 2 + 4 + ... + M
s2 = 0^2 + 2^2 - 4^2 - ... M
M = maior numero par <= n*/

#include <stdio.h>

int main(void) {
    int v, n, m, s1 = 0, s2 = 0, valor_s2 = 0;
    // input
    printf("Digite n:  ");
    scanf("%d", &n);

    // calcular M
    m = n - (n%2);

    for (int i = 0; i <= m/2; i++ ) {
            v = i*2;
            s1 += v; // calcula soma 1

            valor_s2 = v * v;

            if(i % 2 == 0) // se i for divisivel por 2, soma
                s2 -= valor_s2;
            else s2 += valor_s2; // se nao, subtrai
    }
    // output
    printf("A soma 1 e: %d\n", s1);
    printf("A soma 2 e: %d\n", s2);

    return 0;
}
