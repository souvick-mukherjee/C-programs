#include<stdio.h>
void ev_od(int);
void pos_neg(int);
void abs(int);
void main()
{
    int n,ch;
    printf("Enter a number to perform an operation: ");
    scanf("%d",&n);
    printf("Menu\n1. Enter 1 to check whether even or odd.\n2. Enter 2 check whether positive or negative.\n3. Enter 3 to find absolute value.\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    ev_od(n);
    break;
    
    case 2:
    pos_neg(n);
    break;
    case 3:
    abs(n);
    break;
    default:
    printf("Wrong choice");
    break;
    }
}
void ev_od(int x)
{
    if(x%2==0)
    printf("%d is Even no.",x);
    else
    printf("%d is Odd no.",x);
}
void pos_neg(int x)
{
    if(x!=0)
    {
        if(x>0)
        printf("%d is Positive no.",x);
        else
        printf("%d is Negative no.",x);
    }
    else
    printf("Entered no. is 0");
}
void abs(int x)
{
    if(x!=0)
    {
        if(x>0)
        printf("Absolute value: %d",x);
        else
        printf("Absolute value: %d",x+(-2*x));
    }
    else
    printf("Entered no. is 0");
}