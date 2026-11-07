#include <stdio.h>

int main()
{
    int n;
    int t = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tp, sp;
        scanf("%d %d", &tp, &sp);
        if (i == 0)
        {
            s = sp;
        }

        if (s == sp)
        {
            t = tp + 10;
        }
        else
        {
            if (tp <= (t - 10))
            {
                t = t;
            }
            else
            {
                t = t + 10;
            }
        }
    }
    printf("%d\n", t);
    return 0;
}