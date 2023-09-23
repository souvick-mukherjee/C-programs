#include<stdio.h>
int pivot(int ar[],int beg, int end)
{
    int i,j,tmp1,tmp2,piv;
    i=beg+1;
    j=end;
    piv=ar[beg];
    while(i<=j)
    {
        if(ar[i]<piv)
        {
            i++;
        }
        else if(ar[j]>piv)
        {
            j--;   
        }
        else
        {
            tmp1=ar[i];
            ar[i]=ar[j];
            ar[j]=tmp1;
        }
    }
    tmp2=ar[beg];
    ar[beg]=ar[j];
    ar[j]=tmp2;
    piv=ar[j];
    return j;
}
void quickSort(int ar[], int l, int r)
{
    int p;
    if(l<r)
    {
        p=pivot(ar,l,r);
        quickSort(ar,l,p-1);
        quickSort(ar,p+1,r);
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
    quickSort(a,lo,hi);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}