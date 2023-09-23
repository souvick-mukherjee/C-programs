#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INF 9999
int n,g[MAX][MAX],dist[MAX];

void bellmanford()
{
    int i,j;
    dist[0] = 0;
    for(i=1 ; i<n ; i++)
        dist[i] = INF;

    for(i=0 ; i<n ; i++)
    {   j=0;
        while(j<n)
        {
            if(g[i][j]!=0)
            {
                if((dist[i]+g[i][j])<dist[j])
                    dist[j]=g[i][j]+dist[i];
            }
            j++;
        }

    }

    for(i=0 ; i<n ; i++)
        printf("%d  ",dist[i]);
}
void main()
{
    int i,j;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix for the graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bellmanford();
}