#include<stdio.h>
void main()
{int i,j,k,l;
for(i=1;i<=5;i++)
{
    for(j=1;j<=(6-i);j++)
    {
        printf("*");
    }
    for(k=1;k<=(2*(i-1));k++)
    {
        printf(" ");
    }
    for(l=1;l<=(6-i);l++)
    {
        printf("*");
    }
    printf("\n");
}
}