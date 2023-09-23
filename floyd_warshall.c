#include <stdio.h>
#define INF 9999

int graph[10][10], dist_matrix[10][10],v;

void floyd()
{
    //Initialized of dist_matrix
    for(int i=1 ; i<=v ; i++){
        for(int j=1 ; j<=v ; j++){
            dist_matrix[i][j] = graph[i][j];
        }
    }
    //Calculation
    for(int k=1 ; k<=v ; k++){
        for(int i=1 ; i<=v ; i++){
            for(int j=1 ; j<=v ; j++){
                if(dist_matrix[i][k]!=INF && dist_matrix[k][j]!=INF && dist_matrix[i][k]+dist_matrix[k][j]<dist_matrix[i][j]){
                    dist_matrix[i][j]=dist_matrix[i][k]+dist_matrix[k][j];
                }
            }
        }
    }

    //Printing Distance Matrix
    printf("\nFinal Matrix\n");
    for(int i=1 ; i<=v ; i++){
        for(int j=1 ; j<=v ; j++){
            printf("%d  ",dist_matrix[i][j]);
        }
        printf("\n");
    }
}
void main()
 {
    printf("Enter no. of vertices :: ");
    scanf("%d",&v);
    printf("\nEnter Cost Adjacency Matrix (-1 for INF)\n");
    for(int i=1 ; i<=v ; i++){
        for(int j=1 ; j<=v ; j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==-1){
                graph[i][j]=INF;
            }
        }
    }
    floyd();
 }