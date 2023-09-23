#include<stdio.h>
#include<stdlib.h>
int s1[30],top1=-1,s2[30],top2=-1,max=30;
int isEmpty(int l)
{
    if (l==-1)
    return 1;
    else
    return 0;
}
int isFull(int l)
{
    if(l==29)
    return 1;
    else
    return 0;
}
int push(int s[],int x)
{
    if(s==s1)
    {
    if(isFull(top1))
    {
        printf("Queue is full.");
    }
    else
    {
        top1++;
        s[top1]=x;
    }
    }
    else
    {
        if(isFull(top2))
    {
        printf("Queue is full.");
    }
    else
    {
        top2++;
        s[top2]=x;
    }

    }

}
int pop(int s[])
{
    if (s==s1)
    return s1[top1--];
    else
    return s2[top2--];
}
int enqueue(int s[],int x)
{
    push(s,x);
}
int dequeue(int s1[],int s2[],int t1,int t2)
{
    int x;
    if(isEmpty(t2))
    {
        if(isEmpty(t1))
        {
            printf("Queue is empty");
            exit(1);
        }
    }
        else
        {
            while(isEmpty(t1)==0)
            {
                x=pop(s1);
                push(s2,x);
            }
        }

    return pop(s2);

}
int display(int *s1)
{
    int i;
    for(i=0;i<=top1;i++)
    {
        printf("%d ",s1[i]);
    }
    return 0;
}
void main()
{
    int ch,x;
    printf("Menu:\n1. Push an element.\n2. Pop an element.\n3.Display the stack. \n");
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d",&x);
            enqueue(s1,x);
            printf("%d",top1);
            break;
        case 2:
            dequeue(s1,s2,top1,top2);
            break;
        case 3:
            display(s1);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice.");
        }
    }
}
