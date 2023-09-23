#include <stdio.h>

int n = 5;                    /* The number of objects */
item[10]={1,2,3,4,5}
int w[10] = {12, 1, 2, 1, 4}; /* c[i] is the *COST* of the ith object; i.e. what
                YOU PAY to take the object */
int v[10] = {4, 2, 2, 1, 10}; /* v[i] is the *VALUE* of the ith object; i.e.
                what YOU GET for taking the object */
int M = 15,tmp;                   /* The maximum weight you can take */
float p[10];
int sol[10];
void knp()
{
    for(i=0;i<n;i++)
    {
        p[i]=v[i]/w[i];
    }
    //sorting
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]<p[j])
            {
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;

                tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;

                tmp=w[i];
                w[i]=w[j];
                w[j]=tmp;

                tmp=item[i];
                item[i]=item[j];
                item[j]=tmp;
            }
        }
    }
    int max=M;
    int amount,k=0,t=0;
    while(max>0)
    {
        if(max<w[k])
            amount=max;
        else
            amount=w[k];
        max-=amount;
        sol[t]=amount;
        if(max>0)
        {
            printf("Item %d added, remaining:%d",item[k],max);
        }
        else
        {
            max+=amount;
            printf("%d%% of item %d is added.",float(max*100/w[i]),item[k] );
        }
        
    }
}
int main(int argc, char *argv[])
{
    knp();

    return 0;
}