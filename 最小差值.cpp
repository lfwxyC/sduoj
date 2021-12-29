#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;


int main(){
	int n;
	scanf("%d",&n);
	
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a, a + n);
	
	int ans=inf;
	for(int i=0;i<n-1;i++){
		ans = min(ans, abs(a[i] - a[i + 1]));
	}
	
	printf("%d",ans);
	return 0;
}
