#include<stdio.h>
void main()
{
    int ar[50],n,item,i,u,l,pos,f=0;  
    printf("Enter the number of Elements: ");
    scanf("%d",&n);   
    printf("Enter Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &ar[i]);
    printf("Enter search item: ");
    scanf("%d",&item);
    l=ar[0];
    u=ar[n-1];
    pos=-1;
    while(u>l)
    {
        pos=l+((item-ar[l])*(u-l)/(ar[u]-ar[l]));
        if(ar[pos]==item)
        {
            f=1;
            break;
        }
        else if(ar[pos]<item)
        {
            l=pos+1;
        }
        else if(ar[pos]>item)
        {
            u=pos-1;
        }
    }
    if(f==1)
    {
        printf("%d found at index %d",item,pos);
    }
    else
    {
        printf("Item not found");
    }
}