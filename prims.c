#include<stdio.h>
#include<limits.h>
#define MAX 100

int main(){
    int n,i,j,e,u,v;
    int cost[MAX][MAX];
    int total_cost=0,min,no_of_edges=0;
    int visited[MAX];

    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix(0 if no edges):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }
    for(i=0;i<n;i++)
        visited[i]=0;

    visited[0]=1;
    printf("Edges in MST:\n");
    while (no_of_edges < n-1)
    {
        min=INT_MAX;
        for ( i = 0; i < n; i++)
        {
            if(visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j]&&cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        visited[v]=1;
        total_cost  += min;
        no_of_edges++;
        printf("Edge %d: (%d -> %d) Cost = %d\n",no_of_edges,u+1,v+1,min);
    }
    printf("\n MST cost: %d\n",total_cost);
    return 0;
}