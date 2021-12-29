#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n,max=0,cost=0,min=INT_MAX,minCost=INT_MAX;
	scanf("%d",&n);
	
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	}
	
	for(int i=min;i<=max;i++){
		for(int j=0;j<n;j++){
			cost+=(i-a[j])*(i-a[j]);
		}
		
		if(minCost>cost){
			minCost=cost;
		}
		cost=0;
	}
	
	printf("%d",minCost);
	
	return 0;
}
