#include<stdio.h>
#define MAX 10
int a[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void bfs(int start){
    int front=0,rear=0;
    int i;
    for(i=0;i<n;i++)
        visited[i]=0;
    queue[rear++]=start;
    visited[start]=1;

    printf("BFS Traversal: ");
    while(front<rear){
        start=queue[front++];
        printf("%d ",start);

        for(i=0;i<n;i++){
            if(a[start][i]==1 && visited[i]==0){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
int main(){
    int j,i,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrics(%d x %d):\n",n,n);
    for(i=0;i<n;i++){
        for (j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }   
    }
    printf("\nEnter starting vertice(0-%d):",n-1);
    scanf("%d",&start);
    bfs(start);
    return 0;
}