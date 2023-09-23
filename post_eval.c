#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 30
char ex[MAX];
int stack[MAX],top=-1;
void push(int x)
{
   if(top==MAX-1)
   {
      printf("Overflow");
   }
   top++;
   stack[top]=x;
}
int pop()
{
	if(top==-1)
   {
		printf("Underflow");
   }
	return stack[top--];
}
int evaluate(int a, char ch ,int b)
{
   switch (ch)
   {
   case '+':
      return a+b;
      break;
   case '-':
      return a-b;
      break;
   case '*':
      return a*b;
      break;
   case '/':
      return a/b;
      break;
   case '%':
      return a%b;
      break;
   case '^':
      return pow(a,b);
      break;
   default:
      printf("Invalid expression");
   }
}
void main()
{
    int i,s=0,l, res;
   printf("Enter an expression: ");
   gets(ex);
   l=strlen(ex);
   for (i = 0; i < l; i++)
   {
        if(ex[i]>=48 && ex[i]<=57)
        {
            push(ex[i]-48);
        }
        else if(ex[i]=='+' || ex[i]=='-'|| ex[i]=='*' || ex[i]=='/' || ex[i]=='%' ||ex[i]=='^')
        {
            stack[top-1]=evaluate(stack[top-1],ex[i],stack[top]);
            pop();
        }
   }
   res=stack[top];
   printf("\nResult: %d",res);
   
}