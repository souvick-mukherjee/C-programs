#include<stdio.h>

int isPrime(int num)
{
    int i,c=0;
    if(num==1)
    return 1;
    else if(num==2)
    return 0;
    else
    {
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            c++;
        }
        if(c==0)
        return 1;
        else
        return 0;
    }
}


void main()
{
    int n,i,j, k=1;
    printf("Enter no. of columns: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            while(isPrime(k)==0)
            {
                k++;
            }
            printf("%d ",k);
            k++;
        }
        printf("\n");
    }
}
