#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;
node *start=NULL;
void create(int item)
{
    node *tmp,*q;
    tmp=(node *)malloc(sizeof(node));
    tmp->data=item;
    if(start==NULL)
    {
        start=tmp;
        tmp->prev=NULL;
        tmp->next=NULL;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
        q->next=tmp;
        tmp->prev=q;
        tmp->next=NULL;

    }
}
void search(int item)
{
    node *q;
    q=start;
    int pos=1;
    while(q!=NULL)
    {
        if(q->data==item)
        {
            printf("Item %d found at position %d.\n",q->data,pos);
            return;
        }
        q=q->next;
        pos++;
    }
    if(q==NULL)
    printf("Item not found.\n");
}
void main()
{
    int ch, x;
    printf("Menu\n1. Create or Add nodes.\n2. Search an item.");
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
            printf("Enter search item: ");
            scanf("%d",&x);
            search(x);
            break;
            default:
            printf("Wrong choice.");
            exit(1);
        }
    }
}