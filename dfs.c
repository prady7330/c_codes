#include<stdio.h>
void push(int stack[], int val,int* top){
	*top=*top+1;
	stack[*top]=val;
}
int pop(int stack[], int* top){
	int t=stack[*top];
	*top=*top-1;
	return t;
}
void dfs(int adj[100][100],int visited[], int n, int i){
	int stack[100];
	int top=-1;
	push(stack,i,&top);
	visited[i]=1;
	printf("%d ",i);
	int flag=0;
	while(top!=-1){
		flag=0;
		for(int j=0;j<n;++j){
			if(adj[i][j]==1 && visited[j]==0){
				i=j;
				flag=1;
				break;
			}
		}
		if(flag==1){
			push(stack,i,&top);
			visited[i]=1;
			printf("%d ",i);
		}
		if(flag==0){
			pop(stack,&top);
			i=stack[top];
		}
	}
}
int main(){
	printf("enter the number of vertices:\n");
	int n;
	scanf("%d",&n);
	printf("enter the edges:(-1 -1 to end)\n");
	int a,b;
	int adj[100][100];
	int i, j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)
			adj[i][j]=0;
	}
	while(1){
		scanf("%d%d",&a,&b);
		if(a==-1 && b==-1)
			break;
		else{
			adj[a][b]=1;
			adj[b][a]=1;
		}
	}
	int visited[100];
	for(i=0;i<n;++i){
		visited[i]=0;
	}
	printf("depth first traversal:-");
	dfs(adj,visited,n,0);
	return 0;
}