#include<stdio.h>
#include<stdlib.h>
int s1[30],l1=0,s2[30],l2=0;
int enqueue(int s1[],int x)
{
    push(s1, x)
}
int push(int *s1,int x)
{

    if (isFull(l1))
    {
        printf("Stack Overflow./n");
    }
    else
    {
    //printf("Enter element: ");
    //scanf("%d",&s1[l1]);
    s1[l1]=x;

    l1++;
    }
    return 0;
}
int dequeue(int s1[],int s2[])
{
    int x;
    if(isEmpty(l1))
    {
        printf("Stack Underflow./n");
    }
    else
    {
        while(isEmpty(l1)==0)
        {
            x=pop(s1);
            push(s2,x)
        }
    }
}
int pop(int *s1)
{
    int i;
    if(isEmpty(l1))
    {
        printf("Stack Underflow./n");
    }
    else
    {

        /*for(i=0;i<l1;i++)
        {
            s2[i]=s1[l1-1-i];
            l2++;
        }
        for(i=0;i<l2-1;i++)
        {
            s1[i]=s2[l2-1-i];
        }
        printf("%d",s2[l2-1]);
        l1--;*/
        
    }
    return ;
}
int display(int *s1)
{
    int i;
    for(i=0;i<l1;i++)
    {
        printf("%d ",s1[i]);
    }
    return 0;
}
int isEmpty(int l1)
{
    if(l1==0)
        return 1;
    else
        return 0;
}
int isFull(int l1)
{
    if(l1==30)
        return 1;
    else
        return 0;
}
void main()
{
    int ch;
    printf("Menu:\n1. Push an element.\n2. Pop an element.\n3.Display the stack. \n");
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push(s1);
            break;
        case 2:
            pop(s1,s2);
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