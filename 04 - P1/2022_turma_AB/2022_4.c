/*Escreva um programa que leia um n´umero N e escreva o menor n´umero inteiro cujo fatorial seja maior do
que N. Lembre-se que n˜ao existe o fatorial de n´umeros negativos.
Exemplos:
N = 100 Sa´ıda: 5 (4! = 24 e 5! = 120)
N = 6 Sa´ıda: 4 (3! = 6 e 4! = 24)
N = −4 Sa´ıda: 0 (0! = 1)
N = 0 Sa´ıda: 0 (0! = 1)
N = 1 Sa´ıda: 2 (1! = 1 e 2! = 2)*/
#include <stdio.h>

int main(void) {
    int n = 0, m = 0, f = 1;
    printf("Digite o numero:  ");
    scanf("%d", &n);

    while(f <= n) {
        m++;
        f *= m;
    }

    printf("N = %d\n", n);
    printf("%d (%d! = %d)", m, m, f);

    return 0;
}