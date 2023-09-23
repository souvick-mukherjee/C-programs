#include<stdio.h>
int mult(int,int);
void main()
{
    int n1,n2,p;
    printf("Enter two numbers: ");
    scanf("%d %d",&n1,&n2);
    p=mult(n1,n2);
    printf("Product of %d and %d is %d",n1,n2,p);
}
int mult(int n1, int n2)
{
    if(n2==0)
    return 0;
    else
    return n1+mult(n1,n2-1);
}