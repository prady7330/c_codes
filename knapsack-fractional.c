#include<stdio.h>
#include<stdlib.h>
float knapsack(int w, int weight[], int profit[], int n);
void sort(int weight[], int profit[], int n);
int main(){
	printf("enter the number of elements:\n");
	int n;
	scanf("%d",&n);
	int weight[100];
	int profit[100];
	printf("enter the weight and the profit:\n");
	int i;
	for(i=0;i<n;++i){
		scanf("%d",&weight[i]);
		scanf("%d",&profit[i]);
	}
	printf("enter the weight of the knapsack:\n");
	int w;
	scanf("%d",&w);
	float pro;
	pro=knapsack(w,weight,profit,n);
	printf("maximum profit=%f\n",pro);
	return 0;
}
void sort(int weight[], int profit[], int n){
	float av[100];
	int i;
	for(i=0;i<n;++i)
		av[i]=(float)profit[i]/(float)weight[i];
	int j;
	for(i=0;i<n-1;++i){
		for(j=0;j<n-i-1;++j){
			if(av[j]>av[j+1]){
				int t=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=t;

				t=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=t;
			}
		}
	}
}
float knapsack(int w, int weight[], int profit[], int n){
	sort(weight,profit, n);
	int knap=0;
	int index=n-1;
	float pro=0;
	int diff;
	while(knap!=w){
		if(knap+weight[index]>w){
			diff=w-knap;
			knap=knap+diff;
			pro=pro+((float)profit[index]/(float)weight[index])*diff;
		}
		else{
			knap=knap+weight[index];
			pro=pro+profit[index];
		}
		index--;
	}
	return pro;
}