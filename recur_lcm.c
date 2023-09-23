#include <stdio.h>
int lcm(int, int);
int n1,n2,l,x,y;
int main()
{
    printf("Enter the two numbers to find their LCM: ");
    scanf("%d %d", &n1, &n2);
    x=n1;
    y=n2;
    l = lcm(n1, n2);
    printf("The LCM of %d and %d is %d.\n", n1, n2, l);
} 
int lcm(int n1, int n2)
{
    while (n1!= n2)
    {
        if (n1<n2)
            return lcm(n1+x, n2);
        else
            return lcm(n1, n2+y);
            
    }
    return n1;
}