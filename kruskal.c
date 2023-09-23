#include <stdio.h>
#define max 30
int G[max][max], n;
void kruskal();
int find(int belongs[], int vertexno);
void applyunion(int belongs[], int cno1, int cno2);
void sort();
void print();
typedef struct edge
{
    int u, v, w;
} edge;
typedef struct edge_list
{
    edge data[max];
    int n;
} edge_list;
edge_list elist, spanlist;
void kruskal()
{
    int belongs[max], i, j, cno1, cno2;
    elist.n = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (G[i][j] != 0)
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }
        }
        sort();
        for (i = 0; i < n; i++)
            belongs[i] = i;
        spanlist.n = 0;
        for (i = 0; i < elist.n; i++)
        {
            cno1 = find(belongs, elist.data[i].u);
            cno2 = find(belongs, elist.data[i].v);
            if (cno1 != cno2)
            {
                spanlist.data[spanlist.n] = elist.data[i];
                spanlist.n = spanlist.n + 1;
                applyunion(belongs, cno1, cno2);
            }
        }
    }
}
int find(int belongs[], int vertexno)
{
    return belongs[vertexno];
}
void applyunion(int belongs[], int cno1, int cno2)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (belongs[i] == cno2)
            belongs[i] = cno1;
    }
}
void sort()
{
    int i, j;
    edge tmp;
    for (i = 1; i < elist.n; i++)
    {
        for (j = 0; j < elist.n - 1; j++)
        {
            if (elist.data[j].w > elist.data[j + 1].w)
            {
                tmp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = tmp;
            }
        }
    }
}
void print()
{
    int i, c = 0;
    printf("U - V : W\n");
    for (i = 0; i < spanlist.n; i++)
    {
printf("\n%d - %d : %d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
c+=spanlist.data[i].w;
    }
    printf("\nSpanning Tree cost = %d ", c);
}
int main()
{
    int i, j, tc;
    n = 6;
    G[0][0] = 0;
    G[0][1] = 4;
    G[0][2] = 4;
    G[0][3] = 0;
    G[0][4] = 0;
    G[0][5] = 0;
    G[0][6] = 0;
    G[1][0] = 4;
    G[1][1] = 0;
    G[1][2] = 2;
    G[1][3] = 0;
    G[1][4] = 0;
    G[1][5] = 0;
    G[1][6] = 0;
    G[2][0] = 4;
    G[2][1] = 2;
    G[2][2] = 0;
    G[2][3] = 3;
    G[2][4] = 4;
    G[2][5] = 0;
    G[2][6] = 0;
    G[3][0] = 0;
    G[3][1] = 0;
    G[3][2] = 3;
    G[3][3] = 0;
    G[3][4] = 3;
    G[3][5] = 0;
    G[3][6] = 0;
    G[4][0] = 0;
    G[4][1] = 0;
    G[4][2] = 4;
    G[4][3] = 3;
    G[4][4] = 0;
    G[4][5] = 0;
    G[4][6] = 0;
    G[5][0] = 0;
    G[5][1] = 0;
    G[5][2] = 2;
    G[5][3] = 0;
    G[5][4] = 3;
    G[5][5] = 0;
    G[5][6] = 0;
    kruskal();
    print();
}