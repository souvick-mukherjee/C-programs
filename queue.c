#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define true 1
#define false 0
int q[MAX], f=-1,r=-1;
int isEmpty(int r,int f)
{
    if(r==-1 && f==-1)
    {
        return true;
    }
    else if(r<f)
    {
        return true;
    }
}
int isFull(int r, int f)
{
    if(r==MAX-1)
        return true;
}
void enqueue(int x)
{
    if(f==MAX-1)
    {
        printf("Overflow");
    }
    else if(f==-1 && r==-1)
    {
        f++;
        r++;
        q[r]=x;
    }
    else
    {
        r++;
        q[r]=x;
    }
}
int dequeue()
{
    if(f==-1 && r==-1)
    {
        printf("Underflow");
    }
    else if(r<f)
    {
        printf("Underflow");
    }
    else
    {
        return(q[f++]);
    }
}
int count()
{
    int c=0,i;
    for(i=f;i<=r;i++)
    {
        c++;
    }
    return c;
}
void reverse(int ar[])
{
    int i=0;
    for(i=r;i>=f;i--)
    {
        printf("%d  ",ar[i]);
    }
}
void display(int ar[])
{
    int i=0;
    for(i=f;i<=r;i++)
    {
        printf("%d  ",ar[i]);
    }
}
int peek(int ar[])
{
    return(ar[r]);
}
void main()
{
    int ch,n;
    printf("Menu\n1. Insert an element.\n2. Delete an element.\n3. Display elements of queue.\n4. Check if queue is full.\n5. Check if queue is empty.\n6. Display topmost element.\n7. Count no. of elements.\n8. Reverse element of the queue.\n9. Exit operation.\n");
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            printf("\nDeleted element: %d",dequeue());
            break;
        case 3:
            printf("\nElements in the queue: ");
            display(q);
            break;
        case 4:
            if(isFull(r,f))
                printf("\nQueue is full.");
            else
                printf("\nQueue not full.");
            break;
        case 5:
            if(isEmpty(r,f))
                printf("\nQueue is empty.");
            else
                printf("\nQueue not empty.");
            break;
        case 6:
            printf("\nTopmost element: %d",peek(q));
            break;
        case 7:
            printf("\nNo. of elements: %d",count());
            break;
        case 8:
            printf("\nQueue elements in reverse:\n");
            reverse(q);
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("\nWrong choice:");
        }
    }
}