#include<stdio.h>
#define MAX 100
int parent[MAX],rankArr[MAX];
void create(int n){
for(int i=0;i<n;i++){
	parent[i]=i;
	rankArr[i]=0;
	}
}

int find(int x){
if(parent[x] != x)
	parent[x] = find(parent[x]);
	return parent[x];
	}

void unionSet(int x,int y){
int rootX=find(x);
int rootY=find(y);
if (rootX==rootY){
	printf("Elements %d and %d are already in the same set\n",x,y);
	return;
	}

 if(rankArr[rootX]<rankArr[rootY])
 	parent[rootX]=rootY;
 else if(rankArr[rootX]>rankArr[rootY])
 	parent[rootY]=rootX;
 else{
 parent[rootY]=rootX;
 rankArr[rootX]++;
 }
 printf("Union done between  %d and %d\n",x,y);
}

int main(){
	int n,choice,x,y;
	printf("Enter number of elmemnts:");
	scanf("%d",&n);
	create(n);
	printf("\n---Menu--\n");
	printf("1.Union\n2.Find\n3.Exit\n");
	while(1){
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:printf("Enter 2 elements to union:");
			scanf("%d%d",&x,&y);
			if(x>=n || y>=n){
			printf("Invalid elements,range is 0 to %d\n",n-1);
			}
			else{
			unionSet(x,y);
			}
			break;
		case 2:printf("Enter elements to find:");
			scanf("%d",&x);
			if(x>=n){
			printf("Invalid elements,range is 0 to %d\n",n-1);
			}
			else{
			printf("Representative of %d is %d\n",x,find(x));
			}
			break;
		case 3:return 0;
		default:printf("Invalid choice\n");
		}
	}
}
			
