#include<stdio.h>
// void foo(int *const *p)
// {
//    int j=10;
//    *p=&j;
//    printf("%d",**p);
// }
// int main()
// {
//    int i=11;
//    int *p=&i;
//    foo(&p);
//    printf("%d ",*p);
// }
void main()
{
   int i=0;
   while (i++<5)
   {
      printf("in...%d\n",i);
   }
      printf("out...%d\n",i);
   
}