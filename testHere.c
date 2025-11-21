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
    if(! parent[i]){
        i=parent[i];
        return i;
    }
 }

 void union_sets(int i,int j){
    int a=find(i);
    int b=find(j);
    parent[a]=b;
 }

 int main(){
    int i,j,n,e,minCost=0,temp=0,u,v,w;

    struct Edge edge[MAX];
    printf("Enter no of vertices:\n");
    scanf("%d",&n);
    printf("Enter no of edges:\n");
    scanf("%d",&e);
    printf("Enter edges(u,v,w):\n");
    for(i=0;i<e;i++){
        scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for(i=0;i<n;i++)
        parent[i]=i;
        for(i=0;i<e-1;i++){
            for(j=0;j<e-1;j++){
                if(edge[j].w>edge[j+1].w){
                    struct Edge temp=edge[j];
                    edge[j]=edge[j+1];
                    edge[j+1]=temp;

                }
            }
        }
        printf("Edges in MST:\n");
        int count=0;
        for(i=0;i<e&&count<n-1;i++){
            u=edge[i].u;
            v=edge[i].v;
            w=edge[i].w;

        if(find(u)!=find(v)){
            printf("%d-%d:%d\n",u,v,w);
            minCost+=w;
            union_sets(u,v);
            count++;
        }
        }
        printf("Minimum cost=%d",minCost);
        return 0;
    }
 