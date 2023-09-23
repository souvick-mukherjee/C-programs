#include <stdio.h>
int hcf(int, int);
int main()
{
    int n1, n2, h;
    printf("Enter the two numbers to find their HCF: ");
    scanf("%d %d", &n1, &n2);
    h = hcf(n1, n2);
    printf("The HCF of %d and %d is %d.\n", n1, n2, h);
} 
int hcf(int n1, int n2)
{
    while (n1!= n2)
    {
        if (n1>n2)
            return hcf(n1-n2, n2);
        else
            return hcf(n1, n2-n1);
    }
    return n1;
}