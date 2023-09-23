#include<stdio.h>
int prime(int,int);
void main()
{
    int n,f;
    printf("Enter a number: ");
    scanf("%d",&n);
    f=prime(2,n);
    if (f==0)
    printf("%d is a Prime no.",n);
    else
    printf("%d is not a prime no.",n);
}
int prime(int i,int n)
{
    if(i==n-1)
    return 0;
    else
    {
        if(n%i==0)
        return 1;
        else
        return prime(i+1,n);
    }
}