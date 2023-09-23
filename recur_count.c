#include<stdio.h>
int count(int);
void main()
{
    int n,nc;
    printf("Enter a number: ");
    scanf("%d",&n);
    nc=count(n);
    printf("Number of digits in %d is  %d",n,nc);
}
int count(int n)
{
    static int c=0;
    if(n==0)
    return c;
    else
    {
        c++;
        return count(n/10);
    }
}