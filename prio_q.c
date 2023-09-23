#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define true 1
#define false 0
int pq[5][MAX],f[]={-1,-1,-1,-1,-1},r[]={-1,-1,-1,-1,-1};
void enqueue(int p, int x)
{
    if(f[p]==(r[p]+1)%MAX)
    {
        printf("Overflow");
        return;
    }
    else if(f[p]==-1 && r[p]==-1)
    {
        f[p]++;
        r[p]++;
        pq[p][r[p]]=x;
    }
    else if(r[p]==MAX-1 && f[p]!=0)
    {
        r[p]=0;
        pq[p][r[p]]=x;
    }
    else
    {
        r[p]++;
        pq[p][r[p]]=x;
    }
}
int dequeue(int p)
{
    if(r[p]==f[p])
    {
        return(pq[p][f[p]]);
        f[p]=r[p]=-1;
    }
    else if(f[p]==-1 && r[p]==-1)
    {
        printf("Underflow");
        exit(1);
    }
    else if(f[p]==MAX-1)
    {
        return(pq[p][f[p]]);
        f[p]=0;
    }
    else
    {
        return(pq[p][f[p]++]);
    }
}
void display()
{
    int p;
    for(p=0;p<5;p++)
    {int i=f[p];
    while(i!=r[p])
    {
        if(i==MAX-1)
        {
            printf("%d  ",pq[p][i]);
            i=0;
        }
        else
        {
            printf("%d  ",pq[p][i]);
            i++;
        }
    }
    printf("%d  ",pq[p][r[p]]);
    printf("\n");
    }
}
void main()
{
    int ch,p,x;
    printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter priority: ");
            scanf("%d",&p);
            if(p>4)
                printf("Not possible\n");
            else
            {
                printf("Enter data: ");
                scanf("%d",&x);
                enqueue(p,x);
            }
            break;
        case 2:
            printf("Enter priority: ");
            scanf("%d",&p);
            printf("Deleted element: %d\n",dequeue(p));
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1); 
        default:
            printf("Wrong choice!!!");
            break;
        }
    }
}