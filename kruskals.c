#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Edge
{
    int u,v,w;
    /* data */
};

int parent[MAX];

int find(int i){
    while (parent[i]!=i)
    {
        i=parent[i];
        return i;
        /* code */
    }
}

void union_sets(int i,int j){
    int a=find(i);
    int b=find(j);
    parent[a]=b;
}

int main(){
    struct Edge edges[MAX];
    int n,e;
    int i,j,u,v,w;
    int minCost=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    printf("Enter edges(u,v,w):\n");
    for(i=0;i<e;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
        }
    for(i=0;i<n;i++)
        parent[i]=i;
    for(i=0;i<e-1;i++){
        for(j=0;j<e-1;j++){
            if(edges[j].w>edges[j+1].w){
                struct Edge temp = edges[j];
                edges[j] =edges[j+1];
                edges[j+1]=temp;
            }
        }
    }

    printf("Edges in the MST:\n");
    int count=0;
    for (i=0;i<e&&count<n-1;i++){
        u=edges[i].u;
        v=edges[i].v;
        w=edges[i].w;

        if(find(u)!=find(v)){
            printf("%d-%d:%d\n",u,v,w);
            minCost+=w;
            union_sets(u,v);
            count++;
        }
    }
    printf("\nMinimum cost=%d",minCost);
    return 0;
}
