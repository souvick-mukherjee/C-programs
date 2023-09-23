#include<stdio.h>

int M, item[20], w[20], p[20],n,i,j,k,B[20][20],a,b,c;

void find_item(int x, int y)
{
    while(x>0 && y>0)
    {
        if(B[x][y]!=B[x-1][y])
        {
            printf("%d ",x);
            x--;
            y-=w[x];
        }
        else
        x--;
    }
}

void knp()
{
    for(i=0;i<=M;i++)
    {
        B[0][i]=0;
    }
    for(i=0;i<=n;i++)
    {
        B[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(w[i]<=j)
            {
                if( p[i] + B[i-1][j-w[i]] > B[i-1][j] )
                B[i][j]=p[i] + B[i-1][j-w[i]];
                else
                B[i][j]=B[i-1][j];
            }
            else
            B[i][j]=B[i-1][j];
        }
    }

    printf("Knapsack matrix: \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=M;j++)
        {
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    printf("Maximum Profit: %d\n", B[n][M]);

    printf("Items in knapsack: ");
    find_item(n,M);


}


void main()
{
    printf("Enter maximum capacity: ");
    scanf("%d",&M);
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter items:");
    for(i=1;i<=n;i++)
    scanf("%d", &item[i]);
    printf("Enter weights:");
    for(i=1;i<=n;i++)
    scanf("%d", &w[i]);
    printf("Enter profits:");
    for(i=1;i<=n;i++)
    scanf("%d", &p[i]);

    knp();
}