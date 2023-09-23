#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n,c[20][20],i,j,k=0;
char x[20],y[20],b[20][20],sbq[20];
void print_lcs(int p, int q)
{
    //printf("working!!!");
    while(p>0 && q>0)
    {
        //printf("In loop");
        if(b[p][q]=='^')
        {
            sbq[k]=x[p-1];
            k++;
            p--;
            q--;
        }
        else if(b[p][q]=='|')
        p--;
        else
        q--;
    }
    for(i=k;i>=0;i--)
    printf("%c",sbq[i]);
}
void lcs()
{
    
    m=strlen(x);

    
    n=strlen(y);

    for(i=1;i<=m;i++)
    {
        c[i][0]=0;
        b[i][0]='|';
    }
    for(i=1;i<=n;i++)
    {
        c[0][i]=0;
        b[0][i]='_';
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='^';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='_';
            }
        }
    }

    printf("LCS matrix: \n");
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    




}
void main()
{
    printf("Enter string 1: ");
    gets(x);

    printf("Enter string 2: ");
    gets(y);

    lcs();

    printf("Longest subsequence: ");
    print_lcs(m,n);
}