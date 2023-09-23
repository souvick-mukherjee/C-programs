#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *last=NULL;
void create(int item)
{
    node *tmp;
    tmp=(node*)malloc(sizeof(node));
    tmp->data=item;
    if(last==NULL)
    {
        last=tmp;
        last->next=tmp;
    }
    else
    {
        tmp->next=last->next;
        last->next=tmp;
        last=tmp;
    }
}
void del_last()
{
    node *tmp,*q;
    q=last->next;
    while(q->next!=last)
    {
        q=q->next;
    }
    tmp=q->next;
    q->next=last->next;
    last=q;
    free(tmp);
}
void display()
{
    node *q;
    q=last->next;
    while(q!=last)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("%d",last->data);
}
void main()
{
    int ch, x;
    printf("Menu\n1. Create or Add nodes.\n2. Delete last element.\n3. Display.");
    while(1)
    {
        printf("\nEnter a choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter a number: ");
            scanf("%d",&x);
            create(x);
            break;
            case 2:
            del_last();
            break;
            case 3:
            display();
            break;
            default:
            printf("Wrong choice.");
            exit(1);
        }
    }
}