#include<stdio.h>
#include<string.h>
#define MAX 20
#define true 1
#define false 0
int top = -1;
int stack[MAX];

void push(char);
char pop();
void main()
{
    int i,valid=true;
    char exp[MAX],temp;
    printf("Enter expression : ");
    gets(exp);

    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='[')
            {
                push(exp[i]);
            }
        else if( exp[i]==')'|| exp[i]=='}' ||exp[i]==']')
        {
            if(top==-1)
                valid=false;
        
            else
            {
                temp=pop();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    valid=false;
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                    valid=false;
                if(exp[i]==']' && (temp=='(' || temp=='{'))
                    valid = false;
            }
        }
    }
    if(valid==true)
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }
}

void push (char item)
{
    if(top==(MAX-1))
        printf("Stack overflow\n");
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        return (stack[top--]);
    }
}