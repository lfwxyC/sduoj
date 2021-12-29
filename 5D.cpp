#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n+2],l[n],r[n];
	a[0]=a[n+1]=0;
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	stack<int> s;
	// 寻找每个元素的右边界 
	for(int i=1;i<n+2;i++){
		// 单调递增栈 
		while(!s.empty()&&a[s.top()]>a[i]){
			r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	// 清空栈 
	while(!s.empty()){
		s.pop();
	}
	
	// 寻找每个元素的左边界 
	for(int i=n;i>=0;i--){
		while(!s.empty()&&a[s.top()]>a[i]){
			l[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	LL ans=0;
	for(int i=1;i<=n;i++){
		LL now=(LL)a[i]*(LL)(r[i]-l[i]-1);
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}
