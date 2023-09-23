#include <stdio.h>
void main()
{
    int ar[50],n,i,j,temp,min_ind;  
    printf("Enter the number of Elements: ");
    scanf("%d",&n);   
    printf("Enter Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &ar[i]);
    for(i=0;i<n-1;i++)
    {
        min_ind=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[j]<ar[min_ind])
            min_ind=j;
            
            if(min_ind!=i)
            {
                temp=ar[min_ind];
                ar[min_ind]=ar[i];
                ar[i]=temp;
            }
        }
    }
    printf("After Selection sort:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}