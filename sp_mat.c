#include<stdio.h>
void main()
{
    int ar[10][10],r,c,i,j,cnt=0,nonZero,sp[100][3],k=1;
    printf("Enter no. of rows: ");
    scanf("%d",&r);
    printf("Enter no. of columns: ");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element to row %d and column %d: ",i,j);
            scanf("%d",&ar[i][j]);
            if(ar[i][j]==0)
            cnt++;
        }
    }
    if(cnt>(r*c)/2)
    {
        printf("Eligiible for sparse matrix.\n");
        nonZero=(r*c)-cnt;
        sp[0][0]=r;
        sp[0][1]=c;
        sp[0][2]=nonZero;
        for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(ar[i][j]!=0)
            {
                sp[k][0]=i;
                sp[k][1]=j;
                sp[k][2]=ar[i][j];
                k++;
            }
            
        }
    }
    printf("Sparse matrix: \n");
    for (i = 0; i < k; i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",sp[i][j]);
        }
        printf("\n");
    }
    
    }
    else
    printf("Not eligible for Sparse matrix.");
}