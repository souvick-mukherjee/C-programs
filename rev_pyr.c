#include <stdio.h>
void main()
{
    int n,i,j;
    printf("Enter the no. of rows: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        printf(" ");
        for(j=1;j<=n+1-i;j++)
        printf("*");
        for(j=1; j<n+1-i;j++)
        printf("*");
        printf("\n");
    }
}