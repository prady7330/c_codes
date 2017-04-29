#include<stdio.h>
#include<stdlib.h>
struct node{
	int w,v;
};
int max(int a, int b){
	if(a>b) return a;
	else return b;
}
struct node* knapsack(int w, int weight[], int value[], int n){
	int column=w+1;
	int row=n;
	int t[row][column];
	int i;
	int j;
	for(i=0;i<row;++i)
		t[row][0]=0;
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			if(i==0){
				if(j>=weight[i]){
					t[i][j]=value[i];
				}else{
					t[i][j]=0;
				}
			}else{
				if(j<weight[i]){
					t[i][j]=t[i-1][j];
				}else{
					t[i][j]=max(value[i]+t[i-1][j-weight[i]],t[i-1][j]);
				}
			}
		}
	}
	row=row-1;
	column=column-1;
	struct node arr[100];
	int x=0;
	int val=10000;
	while(val!=0){
		if(t[row][column]==t[row-1][column]){
			row=row-1;
			val=t[row][column];
		}
		else{
			arr[x].v=value[row];
			arr[x].w=weight[row];
			x++;
			row=row-1;
			column=column-weight[row+1];
			val=t[row][column];
		}
	}
	arr[x].v=-1;
	arr[x].w=-1;
	struct node* p=arr;
	return p;
}
int main(){
	printf("enter the number of elements:\n");
	int n;
	scanf("%d",&n);
	int weight[100];
	int value[100];
	printf("enter the weight and the values:\n");
	int i;
	for(i=0;i<n;++i)
		scanf("%d%d",&weight[i],&value[i]);
	printf("enter the knapsack weight:\n");
	int w;
	scanf("%d",&w);
	struct node*p=knapsack(w,weight,value,n);
	int index=0;
	int sum=0;
	int pro=0;
	while(p[index].w!=-1 && p[index].v!=-1){
		sum+=p[index].w;
		pro+=p[index].v;
		index++;
	}
	printf("total weight=%d total value=%d\n",sum,pro);
	return 0;
}