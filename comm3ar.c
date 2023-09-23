#include<stdio.h>
void main()
{
    int ar1[100],ar2[100],ar3[100],c[100],n1,n2,n3,i,j,k;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements to the first array: \n");
    for(i=0;i<n1;i++)
    scanf("%d",&ar1[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements to the second array: \n");
    for(j=0;j<n2;j++)
    scanf("%d",&ar2[j]);
    printf("Enter size of third array: ");
    scanf("%d", &n3);
    printf("Enter elements to the third array: \n");
    for(k=0;k<n3;k++)
    scanf("%d",&ar3[k]);
    printf("Common elements: ");
    i=j=k=0;
    while(i<n1 && j<n2 && k<n3)
    {
        if(ar1[i]==ar2[j]&&ar2[j]==ar3[k])
        {
            printf("%d\t",ar1[i]);
            i++;
            j++;
            k++;
        }
        else if(ar1[i]<ar2[j]&&ar1[i]<ar3[k])
        i++;
        else if(ar2[j]<ar3[k])
        j++;
        else
        k++;
    }
    
}