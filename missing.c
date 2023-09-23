#include<stdio.h>
#include<math.h>
void main()
{
    int ar[100], n,i,t1=0,t2=0;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    if(n>=1 && n<=pow(10,6))
    {
        printf("Enter elements to the array:\n");
        for(i=0;i<n-1;i++)
        {
        scanf("%d",&ar[i]);
        if(ar[i]>=1&&ar[i]<=n)
        {
            t1+=ar[i];
        } 
        else
        {
            printf("Input not allowed.");
            break;
        }
        }   
        for(i=1;i<=n;i++)
        t2+=i;
        printf("Missing element: %d",(t2-t1));
        
    }
}