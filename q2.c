#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int q[MAX],f=-1,r=-1;
void enqueue(int item)
{
    if(r==MAX-1)
    {
        printf("Overflow");
        return;
    }
    else if(r==-1 && f==-1)
    {
        f++;
        r++;
        q[r]=item;
    }
    else
    {
        r++;
        q[r]=item;
    }
}
int dequeue()
{
    if(f==-1||f>r)
    {
        printf("Underflow.");
    }
    else
    {
        return(q[f++]);
    }
}
void reverse()
{
    int i=f,j=r,tmp;
    while(i<j)
    {
        tmp=q[i];
        q[i]=q[j];
        q[j]=tmp;
        i++;
        j--;
    }
}
void display()
{
    int i;
    for(i=f;i<=r;i++)
    printf("%d ",q[i]);
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
            display();
            break;
        // case 4:
        //     if(isFull(r,f))
        //         printf("\nQueue is full.");
        //     else
        //         printf("\nQueue not full.");
        //     break;
        // case 5:
        //     if(isEmpty(r,f))
        //         printf("\nQueue is empty.");
        //     else
        //         printf("\nQueue not empty.");
        //     break;
        // case 6:
        //     printf("\nTopmost element: %d",peek(q));
        //     break;
        // case 7:
        //     printf("\nNo. of elements: %d",count());
        //     break;
        case 8:
            printf("\nQueue elements in reverse:\n");
            reverse();
            display();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("\nWrong choice:");
        }
    }
}