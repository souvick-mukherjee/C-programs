#include<stdio.h>
void main()
{
    int n,i,j,x=0,y=1,z,t=1;
    printf("Enter no. of columns: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(t==1)
            printf("%d ",x);
            else if(t==2)
            printf("%d ",y);
            else{
            z=x+y;
            printf("%d ",z);
            x=y;
            y=z;
            }
            t++;
        }
        printf("\n");
    }
}
