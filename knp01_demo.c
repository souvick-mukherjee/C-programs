#include <stdio.h>
int item[10], m[20], w[10], b[10], B[100][100], out[10], n, i, j, M, k = 0, res, wt, profit = 0;
void main()
{
    printf("Enter the number of items:");
    scanf("%d", &n);
    printf("Items:");
    for (i = 1; i <= n; i++)
        scanf("%d", &item[i]);
    printf("Weights:");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Profits:");
    for (i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    printf("Capacity:");
    scanf("%d", &M);
    for (i = 1; i <= M; i++)
        m[i] = i;
    for (j = 0; j <= M; j++)
        B[0][j] = 0;
    for (i = 0; i <= n; i++)
        B[i][0] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (w[i] <= j)
            {
                if ((b[i] + B[i - 1][j - w[i]]) > (B[i - 1][j]))
                    B[i][j] = b[i] + B[i - 1][j - w[i]];
                else
                    B[i][j] = B[i - 1][j];
            }
            else
                B[i][j] = B[i - 1][j];
        }
    }
    printf("Knapsack Matrix\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= M; j++)
        {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    res = B[n][M];
    printf("Maximum profit is:%d\n", res);
    wt = M;
    printf("Items included in knapsack:");
    for (i = n; i > 0 && res > 0; i--)
    {
        if (B[i][M] != B[i - 1][M])
        {
            printf("%d\t", i);
            i = i - 1;
            M = M - w[i];
        }
        else
        {
            i = i - 1;
        }
    }
}