#include <stdio.h>

int main()
{
    int i, j = 0, vetor[1000] = {0}, testes, indice;
    for (i = 1; i <= 1666; i++)
    {
        if (((i % 3) != 0) && ((((i % 1000) % 100) % 10) != 3))
        {
            vetor[j] = i;
            j++;
        }
    }
    scanf("%d", &testes);
    for (i = 1; i <= testes; i++)
    {
        scanf("%d", &indice);
        printf("%d\n", vetor[indice - 1]);
    }

    return 0;
}