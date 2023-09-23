#include <stdio.h>
void main()
{
    int ar[50],n,i,j,temp;  
    printf("Enter the number of Elements: ");
    scanf("%d",&n);   
    printf("Enter Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &ar[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    printf("After Bubble sort:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}