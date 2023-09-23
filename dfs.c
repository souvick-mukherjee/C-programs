#include <stdio.h>
int b[20][20], traverse[20], n;
void dfs(int node)
{
    int x;
    traverse[node] = 1;
    for (x = 1; x <= n; x++)
        if (b[node][x] && !traverse[x])
        {
            printf("\n %d->%d", node, x);
            dfs(x);
        }
}

int main()
{
    int x, y, flag = 0;
    printf("\nEnter number of vertices of the graph :: ");
    scanf("%d", &n);
    for (x = 1; x <= n; x++)
    {
        traverse[x] = 0;
        for (y = 1; y <= n; y++)
            b[x][y] = 0;
    }
    printf("\nEnter the neighboring matrix :: \n");
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
            scanf("%d", &b[x][y]);
    dfs(1);
    printf("\n");
    for (x = 1; x <= n; x++)
    {
        if (traverse[x])
            flag++;
    }
    if (flag == n)
        printf("\nGraph is attached");
    else
        printf("\nGraph is not attached");
    return 0;
}
