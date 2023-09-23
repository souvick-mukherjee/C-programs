#include<stdio.h>
#include<stdlib.h>

int p[20],n,m[10][10],s[10][10];

void print_optimal_parenthesis(int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        print_optimal_parenthesis(i,s[i][j]);
        print_optimal_parenthesis(s[i][j]+1,j);
        printf(")");
    }
}

void matrix_chaining_order()
{
    int i,j,l,k,q;
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;}
        for(l=2;l<=n;l++)
        {
            for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=999999999;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    printf("M[%d][%d] = %d",i-1,j,m[i-1][j]);
    print_optimal_parenthesis(i-1,j);

}
void main()
{
    int i;
    printf("Enter no. of matrices: ");
    scanf("%d",&n);
    printf("Enter sequence array: ");
    for(i=0;i<=n;i++)
    {scanf("%d",&p[i]);}
    printf("Matrix chain order: ");
    matrix_chaining_order();


}