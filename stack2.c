#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int ar[20], ar_r[20], top = -1, top_r = -1;
void push(int a[], int x)
{
    if (top == MAX - 1)
    {
        printf("Overflow");
        exit(1);
    }
    top++;
    a[top] = x;
    // printf("Pushed: %d  Top: %d",a[top], top);
}
void push_r(int a[], int x)
{
    if (top_r == MAX - 1)
    {
        printf("Overflow");
        exit(1);
    }
    top_r += 1;
    a[top_r] = x;
}
int pop(int a[])
{
    if (top == -1)
    {
        printf("Underflow");
        exit(1);
    }
    return a[top--];
}
int pop_r(int a[])
{
    if (top_r == -1)
    {
        printf("Underflow");
        exit(1);
    }
    return a[top_r--];
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
void reverse(int a[])
{
    int i = 0, j = top, tmp, x;
    while (i < j)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
}
void main()
{
    int ch, n;
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            push(ar, n);
            break;
        case 2:
            printf("Popped element: %d", pop(ar));
            break;
        case 3:
            printf("Stack elements: ");
            display(ar);
            break;
        case 4:
            reverse(ar);
            break;
        default:
            printf("Wrong choice");
            exit(1);
            break;
        }
    }
}