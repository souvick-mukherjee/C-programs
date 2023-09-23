#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *last=NULL;
int count()
{
    struct node *q;
    q=last->next;
    int c=1;
    while(q!=last)
    {
        q=q->next;
        c++;
    }
    return c;
}
void add_beg(int item)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    if(last==NULL)
    {
        last=tmp;
        tmp->next=last;
    }
    else
    {
        tmp->next=last->next;
        last->next=tmp;
    }
}
void add_last(int item)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    if(last==NULL)
    {
        last=tmp;
        tmp->next=last;
    }
    else
    {
        tmp->next=last->next;
        last->next=tmp;
        last=tmp;
    }
}
void add_any(int pos, int item)
{
    if(pos==1)
    {
        add_beg(item);
    }
    else if(pos==count()+1)
    {
        add_last(item);
    }
    else if(pos>count()+1)
    {
        printf("Position does not exit.");
        return;
    }
    else
    {
        struct node *tmp, *q;
        q=last->next;
        int i;
        for(i=1;i<pos-1;i++)
        {
            q=q->next;
        }
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->data=item;
        tmp->next=q->next;
        q->next=tmp;
    }
}
void del_beg()
{
    struct node *tmp;
    tmp=last->next;
    last->next=tmp->next;
    free(tmp);
}
void del_last()
{
    struct node *tmp,*q;
    q=last->next;
    while(q->next!=last)
    {
        q=q->next;
    }
    tmp=q->next;
    last=q;
    q->next=tmp->next;
    free(tmp);
}
void del_any(int pos)
{
    int i;
    struct node *tmp, *q;
    q=last->next;
    if(pos==1)
    del_beg();
    else if(pos==count())
    del_last();
    else if(pos>count()){
    printf("Position does not exist.");
    return;}
    else
    {
        for(i=1;i<pos-1;i++)
        q=q->next;
        tmp=q->next;
        q->next=tmp->next;
        free(tmp);
    }
}
void display()
{
    struct node *q;
    if(last==NULL)
    {
        printf("No nodes in the list");
        return;
    }
    //printf("count...%d",count());
    q=last->next;
    //printf("q...%d\n",q->data);
    //printf("head...%d\n",last->next->data);
    printf("The elements are: \n");
    do
    {
        printf("%d ",q->data);
        q=q->next;
    }while(q!=last);
    printf("%d ",last->data);
}
void search(int item)
{
    struct node *q;
    int f=0;
    q=last->next;
    do{
        if(q->data==item)
        {
            f=1;
            break;
        }
        else
        {
            q=q->next;
        }
    }while(q!=last);
    if(f==1)
        printf("Found!!!");
    else
        printf("Not found.");
}
int maximum()
{
    struct node *q;
    
    int max=0;
    if(last==NULL){
    printf("No nodes in the list");
    return 0;}
    q=last->next;
    do{
        if(q->data>max)
        max=q->data;
        q=q->next;
    }while(q!=last);
    
    return max;
}
int mean()
{
    struct node *q;
    
    int sum=0,c=0;
    float avg;
    if(last==NULL){
    printf("No nodes in the list");
    return 0;}
    q=last->next;
    do
    {
         c++;
        sum+=q->data;
        q=q->next;
    }while(q!=last);
    c++;
    sum+=last->data;
    avg=(float)sum/c;
    
    return avg;
}
void main()
{
    int ch,x,p,i;
    printf("Menu:\n1. Insert a node at the beginning of the list.\n2. Insert a node at the end of the list.\n3. Insert a node at a particular position in the list.\n4. Delete a node from the beginning of the list.\n5. Delete a node from the end of the list.\n6. Delete a node from a particular position in the list.\n7. Traverse the list and print all the elements in the list.\n8. Search for a particular element in the list.\n9. Find and print the maximum value present in the list.\n10. Find mean of the elements present in the list.\n11. Exit operation.\n");
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
        printf("Maximum value in the list: %d",maximum());
        break;
    case 10:
        printf("Mean of the elements: %d",mean());
        break; 
    case 11:
        exit(1);
        break;
    default:
        printf("wrong Choice.");
        break;
    }
    }
}