#include<stdio.h>
void main()
{
    int ar1[]={2,3,7,8,12},ar2[]={5,9,15},ar3[20],n1=5,n2=3,i=0,j=0,k=0,m;
    while(i<n1&&j<n2)
    {
        if(ar1[i]<ar2[j])
        {
            ar3[k]=ar1[i];
            i++;
        }
        else
        {
            ar3[k]=ar2[j];
            j++;
        }
        k++;
    }
    if(i==n1)
    {
        for(m=j;m<n2;m++)
        {
            ar3[k]=ar2[m];
            k++;
        }
    }
    else if (j==n2)
    {
        for(m=i;m<n1;m++)
        {
            ar3[k]=ar1[m];
            k++;
        }
    }
    printf("Merged Array:\n");
    for(i=0;i<k;i++)
    {
        printf("%d ",ar3[i]);
    }
    
}