#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
void add_beg(int item)
{
    struct node *tmp,*q;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->prev=NULL;
    if(start==NULL)
    {
        start=tmp;
        tmp->next=NULL;
    }
    else{
    tmp->next=start;
    start->prev=tmp;
    start=tmp;}
}
void add_last(int item)
{
    struct node *tmp,*q;
    
    q=start;
    while(q->next!=NULL)
    {
        q=q->next;
        
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    q->next=tmp;
    tmp->next=NULL;
    tmp->prev=q;
}
void add_any(int pos, int item)
{
    struct node *tmp,*q;
    int i;
    if(pos==1)
    {
        add_beg(item);
    }
    else{
    q=start;
    for(i=1;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("Not possible.");
            return;
        }
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->next=q->next;
    q->next->prev=tmp;
    q->next=tmp;
    tmp->prev=q;}
}
void del_beg()
{
    struct node *tmp,*q;
    tmp=start;
    start=tmp->next;
    start->prev=NULL;
    free(tmp);
}
void del_last()
{
    struct node *tmp,*q;
    q=start;
    while(q->next->next!=NULL)
    {
        q=q->next;
    }
    tmp=q->next;
    free(tmp);
}
void del_any(int pos)
{
    struct node *tmp,*q;
    int i;
    if(pos==1)
    {
        del_beg();
    }
    else
    {
        q=start;
        for(i=1;i<pos-1;i++)
        {
            q=q->next;
            if(q->next==NULL)
            {
                printf("Not Posiible.");
                return;
            }
        }
        tmp=q->next;
        q->next=tmp->next;
        tmp->next->prev=q;
        free(tmp);
    }
}
void display()
{
    struct node *q;
    q=start;
    if(q==NULL){
    printf("No nodes in the list");
    return;}
    else{
    printf("The elements are: \n");
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    }
}
void count()
{
    struct node *tmp,*q;
    q=start;
    int c=0;
    while(q!=NULL)
    {
        q=q->next;
        c++;
    }
    printf("No. of Nodes: %d",c);
}
void search(int item)
{
    struct node *tmp,*q;
    int pos=1,f=0;
    q=start;
    while(q!=NULL)
    {
        if(q->data==item)
        {
            printf("%d found at position %d",item,pos);
            break;
        }
        q=q->next;
        pos++;
    }
    if(f==1)
    printf("Not found.\n");
}
void reverse()
{
    struct node *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    int c=1;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    struct node *q;
    q=start;
    if(q==NULL){
    printf("No nodes in the list");
    return;}
    else{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    }
    printf("\n");
}
void main()
{
    int ch,x,p,i;
    printf("Menu:\n1. Insert a node at the beginning of the list.\n2. Insert a node at the end of the list.\n3. Insert a node at a particular position in the list.\n4. Delete a node from the beginning of the list.\n5. Delete a node from the end of the list.\n6. Delete a node from a particular position in the list.\n7. Traverse the list and print all the elements in the list.\n8. Search for a particular element in the list.\n9. Count the number of nodes in the list.\n10. Create reverse of the list.\n11. Exit operation.\n");
    while(1)
    {
    printf("Enter choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter data: ");
        scanf("%d",&x);
        add_beg(x);
        break;
    case 2:
        printf("Enter data: ");
        scanf("%d",&x);
        add_last(x);
        break;
    case 3:
        printf("Enter position: ");
        scanf("%d",&p);
        printf("Enter data: ");
        scanf("%d",&x);
        add_any(p,x);
        break;
    case 4:
        del_beg();
        break;
    case 5:
        del_last();
        break;
    case 6:
        printf("Enter position: ");
        scanf("%d",&p);
        del_any(p);
        break;
    case 7:
        display();
        break;
    case 8:
        printf("Enter search item: ");
        scanf("%d",&i);
        search(i);
        break;
    case 9:
        count();
        break;
    case 10:
        printf("The list in reverse: \n");
        reverse();
        break;
    case 11:
        exit(1);
        break;
    default:
        printf("Wrong Choice.");
    }
    }
}