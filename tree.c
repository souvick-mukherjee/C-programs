#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node): ");
    scanf("%d", &x);

    if(x==-1)
        return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d: ",x);
    p->left=create();
    printf("Enter right child of %d: ",x);
    p->right=create();
    return p;
}
// void inorder(node *t)
// {
//     if(t!=NULL)
//     {
//         inorder(t->left);
//         printf(" %d",t->data);
//         inorder(t->right);
//     }
// }
void inorder(node *t)
{
    int top=-1;
    node *s[30], *curr=t, *p,*d;
    while(1)
    {
        if(curr!=NULL && curr->left!=p)
        {
            s[++top]=curr;
            p=curr;
            curr=curr->left;
        }
        else if(curr==NULL && top!=-1)
        {
            d=p;
            printf(" %d",*s[top--]);
            curr=p->right;
            if(curr==NULL)
            {
                curr=s[top];
            }
        }
        else if (curr==NULL && top==-1)
        {
            break;
        }
        
    }
}
void preorder(node *t)
{
    if(t!=NULL)
    {
        printf(" %d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf(" %d",t->data);
    }
}
int count(node *t)
{
    if(t==NULL)
        return 0;
    else
        return(count(t->left)+count(t->right)+1);
}
int leafnode(node *t)
{
    if(t==NULL)
        return 0;
    else if((t->left==NULL)&&(t->right==NULL))
        return 1;
    else
        return(leafnode(t->left)+leafnode(t->right));
}
int nonleafnode(node *t)
{
    if((t==NULL)||((t->left==NULL)&&(t->right==NULL)))
        return 0;
    else
        return(nonleafnode(t->left)+nonleafnode(t->right)+1);
}
node* search(node *t,int item)
{   
    if(t!=NULL)
    {
        search(t->left,item);
        printf("%d\n",t->data);
        if(t->data==item)
        {
            printf("___FOUND___\n");
            exit(1);
        }
        search(t->right,item);
    }    
}
void main()
{
    node *root;
    int choice,c,key,x;
    while(1)
    {
        printf("\n");
        printf("1. Create\n");
        printf("2. Inorder\n");
        printf("3. Count\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        root=create();
        break;
    case 2:
        inorder(root);
        break;
    case 3:
        printf("No. of nodes: %d",count(root));
        break;
    case 4:
        printf("Enter search item: ");
        scanf("%d",&x);
        search(root,x);
        break;
    default:
        printf("Wrong choice!!");

    }
    }
}
