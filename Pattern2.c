#include<stdio.h>
void main()
{int i,j;
for(i=65;i<=69;i++)
{
    if(i%2==0)
    {
        for(j=65+32;j<=i+32;j++)
        printf("%c",j);
    }
    else
    {
        for(j=65;j<=i;j++)
        printf("%c",j);
    }
    printf("\n");
}
}