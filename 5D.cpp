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
	// Ѱ��ÿ��Ԫ�ص��ұ߽� 
	for(int i=1;i<n+2;i++){
		// ��������ջ 
		while(!s.empty()&&a[s.top()]>a[i]){
			r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	// ���ջ 
	while(!s.empty()){
		s.pop();
	}
	
	// Ѱ��ÿ��Ԫ�ص���߽� 
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
