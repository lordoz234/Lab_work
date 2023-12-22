#include <stdio.h>
#include <stdlib.h>

int lab(int n, int m, int t, int s, int **a)
{
    if (n < 0 || m < 0 || n >= t || m >= s)
    {
        return 0;
    }
    if (a[n][m] == 0 || a[n][m] == 2)
    {
        return 0;
    }
    if (n == t - 1 && m == s - 1)
    {
        return 1;
    }
    if (a[n][m] == 1)
    {
        a[n][m] = 2;
        return lab(n + 1, m, t, s, a) + lab(n, m + 1, t, s, a) + lab(n - 1, m, t, s, a) + lab(n, m - 1, t, s, a);
    }
}

int main()
{
    int n = 0;
    int m = 0;
    int t, s;
    scanf("%d", &t);
    scanf("%d", &s);
    int **a = malloc(t * sizeof(int *));

    for (int i = 0; i < t; ++i)
    {
        a[i] = malloc(s * sizeof(int *));
    }
    for (int x = 0; x < t; ++x)
    {
        for (int y = 0; y < s; ++y)
        {
            scanf("%d", &a[x][y]);
        }
    }
    if (lab(n, m, t, s, a) == 0)
    {
        printf("No way");
    }
    else
    {
        for (int i = 0; i < t; ++i)
        {
            printf("\n");
            for (int j = 0; j < s; ++j)
            {
                if (a[i][j] == 2 || (i == t - 1 && j == s - 1 && a[i][j] == 1))
                {
                    printf("1");
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }
}
