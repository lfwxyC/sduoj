#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int a[n];
	deque<int> d(k);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++){
		// 单调递增队列 
		while(!d.empty()&&d.front()<=i-k){ // 下标不在k个元素中时出队 
			d.pop_front();
		}
		while(!d.empty()&&a[d.back()]>a[i]){ // 要入队的元素大于队尾元素时，队尾元素出队 
			d.pop_back();
		}
		d.push_back(i);
		
		if(i>=k-1){
			printf("%d ",a[d.front()]); // 队首元素为最小值 
		}
	}
	printf("\n");
	
	// 清空队列 
	while(!d.empty()){
		d.pop_front();
	}
	
	for(int i=0;i<n;i++){
		// 单调递减队列 
		while(!d.empty()&&d.front()<=i-k){
			d.pop_front();
		}
		while(!d.empty()&&a[d.back()]<a[i]){
			d.pop_back();
		}
		d.push_back(i);
		
		if(i>=k-1){
			printf("%d ",a[d.front()]); // 队首元素为最大值 
		}
	}
	printf("\n");
	
	return 0;
}
