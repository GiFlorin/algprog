/*Conversor de numeros base 10 para base 2*/
#include <stdio.h>

#define N_BITS 5

int main(void) {
    int n10, b2[N_BITS] = {0}, q;
    printf("Digite o numero que voce quer converter:  ");
    scanf("%d", &n10);
    q = n10;

    for (int i = 0; i < N_BITS; i++)
    {
        b2[N_BITS - i - 1] = q % 2;
        q /= 2;
    }
    printf("%d em base 10 e igual a ");
    for (int i = 0; i < N_BITS; i++)
    {
        printf("%d", b2[i]);
    }

    return 0;
}
