#include<stdio.h>
void main()
{
    int ar[100],n,i,x,y,z;
    printf("Enter no.of terms: ");
    scanf("%d",&n);
    ar[0]=x=0;
    ar[1]=y=1;
    for(i=2;i<n;i++)
    {
        z=x+y;
        ar[i]=z;
        x=y; y=z;
    }
    printf("Fibonacci series upto %d terms: \n",n);
    for(i=0;i<n;i++)
    printf("%d ",ar[i]);
}