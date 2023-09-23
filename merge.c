#include<stdio.h>
void main()
{
    int ar1[10],ar2[10],ar3[20],i,n1,n2;
    printf("Enter no. of elements for array 1: ");
    scanf("%d",&n1);
    printf("Enter elements to the array: \n");
    for(i=0;i<n1;i++)
    scanf("%d",&ar1[i]);
    printf("Enter no. of elements for array 2: ");
    scanf("%d",&n2);
    printf("Enter elements to the array: \n");
    for(i=0;i<n2;i++)
    scanf("%d",&ar2[i]);
    
    for(i=0;i<n1;i++)
    ar3[i]=ar1[i];
    for(i=n1;i<(n1+n2);i++)
    ar3[i]=ar2[i-n1];

    printf("After Merging:");
    for(i=0;i<(n1+n2);i++)
    printf("%d ",ar3[i]);
}