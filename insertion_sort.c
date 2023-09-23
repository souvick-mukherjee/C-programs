#include<stdio.h>
void main()
{
    int ar[50],n,i,j,temp,key;  
    printf("Enter the number of Elements: ");
    scanf("%d",&n);   
    printf("Enter Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &ar[i]);
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=ar[i];
        while(j>=0 && ar[j]>key)
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=key;
    }
    printf("After Insertion sort:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}