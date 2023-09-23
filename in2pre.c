#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max 30
char infix[max], prefix[max];
int stack[max],top=0;
void push(int);
int pop();
int prec(char);
void in_to_pre();
int main()
{
    int len,i;
    printf("Enter infix: ");
    fflush(stdin);
    gets(infix);
    strrev(infix);
    //len=strlen(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    in_to_pre();
    printf("prefix: %s\n",prefix);
}
void in_to_pre()
{
    int i,p=0,type,precedence,len;
    char next;
    stack[top]='#';
    len=strlen(infix);
    infix[len]='#';
    for(i=0;infix[i]!='#';i++)
    {
        switch(infix[i])
        {
        case '(':
            push(infix[i]);
            break;
        case ')':
            while((next=pop())!='(')
                    prefix[p++]=next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        precedence=prec(infix[i]);
        while(stack[top]!='#' && precedence<prec(stack[top]))
            prefix[p++]=pop();
        push(infix[i]);
        break;
        default:
            prefix[p++]=infix[i];

        }
    }
    while (stack[top]!='#')
        prefix[p++]=pop();
    strrev(prefix);
    prefix[p]='\0';
}
int prec(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
}
void push(int symbol)
{
    if(top>max)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    else
    {
        top=top+1;
        stack[top]=symbol;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    else
        return(stack[top--]);
}