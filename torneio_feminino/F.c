#include <stdio.h>

int main()
{
    int n;
    int tabuleiro[11][11] = {0};
    int possivel = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int d, r, l, c;
        scanf("%d %d %d %d", &d, &l, &r, &c);
        if (d == 0) // barco na horizontal
        {
            for (int j = 0; j < l; j++)
            {
                if ((tabuleiro[r][c + j] == 1) || (c + j > 10))
                {
                    possivel = 0;
                }
                else
                    tabuleiro[r][c + j] = 1;
            }
        }
        else // barco na vertical
        {
            for (int j = 0; j < l; j++)
            {
                if ((tabuleiro[r + j][c] == 1) || (r + j > 10))
                {
                    possivel = 0;
                }
                else
                    tabuleiro[r + j][c] = 1;
            }
        }
    }

    if (possivel)
        printf("Y\n");
    else
        printf("N\n");
    return 0;
}