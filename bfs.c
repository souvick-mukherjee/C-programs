#include <stdio.h>
int a[20][20], q[20], visited[20], n , front = 0, rear = -1,i,j;
void bfs(int v)
{
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(a[v][i] && !visited[i])
            q[++rear] = i;
        if(front <= rear)
        {
            visited[q[front]] = 1;
            bfs(q[front++]);
        }
    }
}

void main()

{
    int v,i;
    printf("Enter no. of vertices :: ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++)
    {
        q[i]=0;
        visited[i] = 0;
    }
    printf("\nEnter Graph Data in Matrix form :: \n");
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            scanf("%d",&a[i][j]);
        }
 }
    printf("\nEnter the starting vertex :: ");
    scanf("%d",&v);
    bfs(v);
    printf("\nThe node which are reachable are :: ");
    for(i=1 ; i<=n ; i++)
    {
        if(visited[i])
            printf("%d\t",i);
        else
            printf("\nBFS is not possible");
    }
    return 0;

}

