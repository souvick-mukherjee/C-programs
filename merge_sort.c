#include<stdio.h>
void merge(int ar[],int beg, int mid, int end)
{
    int i,j,index,k,temp[20];
    i=beg;
    j=mid+1;
    index=0;
    int x=beg;
    while(i<=mid && j<=end)
    {
        if(ar[i]<ar[j])
        {
            temp[index]=ar[i];
            i++;
        }
        else
        {
            temp[index]=ar[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=ar[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=ar[i];
            index++;
            i++;
        }
    }
    k=0;
    while(k<index)
    {
        ar[x]=temp[k];
        x++;
        k++;
    }
}
void mergeSort(int ar[],int l,int r)
{
    int m;
    if(r>l)
    {
    m=(l+r)/2;
    mergeSort(ar,l,m);
    mergeSort(ar,m+1,r);
    merge(ar,l,m,r);
    }
}
void main()
{
    int a[20],n,i,lo,hi;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter an array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lo=0;
    hi=n-1;
    mergeSort(a,lo,hi);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}