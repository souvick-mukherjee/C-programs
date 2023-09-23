#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
int count()
{
    struct node *q;
    int c=0;
    q=start;
    if(q==NULL)
    return 0;
    else{
        c=1;
    while(q->next!=NULL)
    {
        q=q->next;
        c++;
    }
    return c;}
}
void add_beg(int item)
{
    struct node *tmp;
    tmp =(struct node *)malloc(sizeof(struct node));
    tmp-> data=item;
    tmp-> next=start;
    start=tmp;
}
void add_last(int item)
{
    struct node *tmp, *q;
    q=start;
    while (q->next!=NULL)
    {
        q=q->next;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp-> data=item;
    q->next=tmp;
    tmp->next=NULL;
}
void add_any(int pos, int item)
{
    int i;
    struct node *tmp, *q;
    q=start;
    if(pos==1)
    add_beg(item);
    else if(pos==count()+1)
    add_last(item);
    else if(pos>count()+1)
    printf("Not Possible");
    else
    {
        for(i=1;i<pos-1;i++)
            q=q->next;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->next=q->next;
        tmp->data=item;
        q->next=tmp;
    }
}
void del_beg()
{
    struct node *tmp;
    tmp=start;
    start=tmp->next;
    free(tmp);
}
void del_last()
{
    struct node *tmp, *q;
    q=start;
    while(q->next->next!=NULL)
        q=q->next;
    tmp=q->next;
    q->next=tmp->next;
    free(tmp);
}
void del_any(int pos)
{
    int i;
    struct node *tmp, *q;
    q=start;
    if(pos==1)
    del_beg();
    else if(pos==count())
    del_last();
    else if(pos>count())
    printf("Not Possible");
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
void search(int item)
{
    struct node *q;
    int f=0;
    q=start;
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
    }while(q!=NULL);
    if(f==1)
        printf("Found!!!");
    else
        printf("Not found.");
}
void reverse()
{
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
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
}
void desc_sort()
{
    struct node *curr, *index;
    int temp;
    curr=start;
    index=NULL;
    if(start==NULL)
    {
        printf("No nodes present");
        return;
    }
    else
    {
        while(curr!=NULL)
        {
            index=curr->next;
            while(index!=NULL)
            {
                if(curr->data>index->data)
                {
                    temp=curr->data;
                    curr->data=index->data;
                    index->data=temp;
                }
                index=index->next;
            }
            curr=curr->next;
        }
    }
    reverse();
}
int maximum()
{
    struct node *q;
    q=start;
    int max=0;
    if(q==NULL){
    printf("No nodes in the list");
    return 0;}
    else{
    do{
        if(q->data>max)
        max=q->data;
        q=q->next;
    }while(q!=NULL);
    }
    return max;
}
int mean()
{
    struct node *q;
    q=start;
    int sum=0,c=0;
    float avg;
    if(q==NULL){
    printf("No nodes in the list");
    return 0;}
    else
    {
        do{
            c++;
            sum+=q->data;
            q=q->next;
        }while(q!=NULL);
        avg=(float)sum/c;
    }
    return avg;
}
void main()
{
    int ch,x,p,i;
    printf("Menu:\n1. Insert a node at the beginning of the list.\n2. Insert a node at the end of the list.\n3. Insert a node at a particular position in the list.\n4. Delete a node from the beginning of the list.\n5. Delete a node from the end of the list.\n6. Delete a node from a particular position in the list.\n7. Traverse the list and print all the elements in the list.\n8. Search for a particular element in the list.\n9. Sort the elements in the list in the descending order.\n10. Find and print the maximum value present in the list.\n11. Find mean of the elements present in the list.\n12. Traverse the list in reverse order and print the elements.\n13. Exit operation.\n");
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
        printf("The list in descending order:\n");
        desc_sort();
        break;
    case 10:
        printf("Maximum value in the list: %d",maximum());
        break;
    case 11:
        printf("Mean of the elements: %d",mean());
        break;
    case 12:
        printf("The list in reverse: ");
        reverse();
        break;
    case 13:
        exit(1);
        break;
    
    default:
        printf("wrong Choice.");
        break;
    }
    }
}