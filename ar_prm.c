#include<stdio.h>
void main()
{
    int ar[100],n,i,j,c,k=0;
    printf("Enter range: ");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        c=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                c=1;
                break;
            }
            
        }
        if(c==0)
        {
            ar[k]=i;
            k++;
        }
    }
    printf("Prime nos. \n");
    for(i=0;i<k;i++)
    printf("%d ",ar[i]);
}