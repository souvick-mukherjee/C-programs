#include<stdio.h>
void main()
{
    int ar[50],n,item,i,u,l,mid,f=0;  
    printf("Enter the number of Elements: ");
    scanf("%d",&n);   
    printf("Enter Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &ar[i]);
    printf("Enter search item: ");
    scanf("%d",&item);
    l=ar[0];
    u=ar[n-1];
    mid=-1;
    while(u>l)
    {
        mid=(u+l)/2;
        if(ar[mid]==item)
        {
            f=1;
            break;
        }
        else if(ar[mid]<item)
        {
            l=mid+1;
        }
        else if(ar[mid]>item)
        {
            u=mid-1;
        }
    }
    if(f==1)
    {
        printf("%d found at index %d",item,mid);
    }
    else
    {
        printf("Item not found");
    }
}