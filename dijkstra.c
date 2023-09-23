#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define INF 9999

int n,i,j,g[MAX][MAX],dist[MAX],mark[MAX],curr;
int minIndex()
{
    int i, min=99999,loc;
    for(i=0;i<n;i++)
    {
        if(dist[i]<min && mark[i]!=1)
        {
             min=dist[i];
             loc=i;
        }

    }
     mark[loc]=1;
    return loc;
}
void dks()
{
    int curr;

    for(i=0;i<n;i++)
    {
        curr=minIndex();
        for(j=0;j<n;j++)
        {
            if(g[curr][j]!=0 && (g[curr][j]+dist[curr])<dist[j])
            {
                dist[j]=g[curr][j]+dist[curr];
            }
        }
        //printf("%d ",dist[i]);

    }
    for(i=0;i<n;i++)
    {

        printf("%d ",dist[i]);
    }

}


void main()
{
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix for the graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
        mark[i]=0;
        dist[i]=((i==0)?0:INF);
    }
    dks();

}
