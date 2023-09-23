#include <stdio.h>
    int max(int[], int, int);
    void main()
    {
        int n,m,ar[20],i;
        printf("Enter size of the array:");
        scanf("%d", &n);
        printf("Enter the array:\n");
        for (i = 0; i < n ; i++) 
            scanf("%d", &ar[i]);
            m = ar[0];
            m = max(ar,n-1,m);
            printf("The largest number in the array is: %d\n", m);
    }
 
    int max(int ar[], int i, int m)
    {
        if (i == 0)
            return m;
        if (i > 0) 
        {
            if (ar[i] > m)
            {
                m = ar[i];
            }
            return max(ar, i - 1, m);
        }
    }