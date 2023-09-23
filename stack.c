#include <stdio.h>
#include <stdlib.h>
int ar[30], top = -1;
int isEmpty(int l)
{
    if (l == -1)
        return 1;
    else
        return 0;
}
int isFull(int l)
{
    if (l == 29)
        return 1;
    else
        return 0;
}
int push(int a[])
{
    int n;
    if (isFull(top))
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &n);
        top++;
        a[top] = n;
    }
    return 0;
}
int pop(int a[])
{
    if (isEmpty(top))
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        printf("%d\n", a[top]);
        top--;
    }
    return 0;
}
int display(int a[])
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
int peek(int a[])
{
    printf("Top of stack: %d\n", a[top]);
    return 0;
}
int reverse(int a[])
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
int count()
{
    printf("No. of elements: %d\n", top + 1);
}
int search(int a[])
{
    int item, f = 0, i;
    printf("Enter search item: ");
    scanf("%d", &item);
    for (i = 0; i <= top; i++)
    {
        if (a[i] == item)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
        printf("%d found in position %d\n", item, i);
    else
        printf("Not found.\n");
}
void main()
{
    int ch;
    printf("Menu:\n1. Push an element.\n2. Pop an element.\n3.Display the stack. \n4. Find peek element. \n5. Check if stack is empty. \n6. Check if stack is full. \n7. Find reverse. \n8. Count no. of elements. \n9. Search an element. \n10. Exit operation.\n");
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(ar);
            break;
        case 2:
            pop(ar);
            break;
        case 3:
            display(ar);
            break;
        case 4:
            peek(ar);
            break;
        case 5:
            if (isEmpty(top))
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 6:
            if (isFull(top))
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 7:
            reverse(ar);
            break;
        case 8:
            count();
            break;
        case 9:
            search(ar);
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Wrong choice.\n");
        }
    }
}
