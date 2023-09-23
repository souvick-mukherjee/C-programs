#include<stdio.h>
# include<stdbool.h>
#include<math.h>
#include<stdlib.h>
int q[10], i, k=1,n;
void nQueens(int q[],int k,int n)
{
    int i;

    if(k==n+1){
        for(i=1;i<=n;i++)
          printf(" %d",q[i]);
    exit(0);
}
    for(i=1;i<=n;i++)
    {
        q[k]=i;
        if(fes(q,k))
            nQueens(q,k+1,n);
    }
}


int fes(int q[],int k)
{
    int i;
    for(i=1;i<=k-1;i++)
    {
        if((q[k]==q[i])||(abs(q[i]-q[k])==abs(i-k)))
            return false;
    }
    return true;
}
int main()
{

    printf("Enter no. of rows and column:");
    scanf("%d", &n);
    nQueens(q,k,n);
}