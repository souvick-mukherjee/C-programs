#include<stdio.h>
#include<string.h>
void main()
{
    int n,i,f=0;
    scanf("%d",&n);
    char c[n];
    scanf("%s",c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='H'&&c[i+1]=='H')
        {f=1;
        break;}
        else if(c[i]=='.')
        c[i]='B';
    }
    if(f==1)
    printf("NO");
    else
    {
        printf("YES\n");
        puts(c);
    }
}