#include <stdio.h>
#include <math.h>

int main()
{
    int testes, caixas, vetor_caixas[50] = {0}, i, c, min = pow(10, 7), soma = 0;
    scanf("%d", &testes);
    for (i = 1; i <= testes; i++)
    { // quantos testes

        scanf("%d", &caixas);

        for (c = 0; c < caixas; c++)
        { // doces por caixas
            scanf("%d", &vetor_caixas[c]);
        }

        for (c = 0; c < caixas; c++)
        {
            if (vetor_caixas[c] < min)
            {
                min = vetor_caixas[c];
            }
        }

        for (c = 0; c < caixas; c++)
        {
            soma = soma + (vetor_caixas[c] - min);
        }

        printf("%d\n", soma);
        soma = 0;
        min = pow(10, 7);

        for (c = 0; c < caixas; c++)
        {
            vetor_caixas[c] = 0;
        }
    }

    return 0;
}