#include<bits/stdc++.h>
using namespace std;

// 比较x先看还是y先看所用时间少 
bool cmp(pair<int,int> x,pair<int,int> y){
	int ans1=x.first+y.second+max(x.second,y.first);
	int ans2=y.first+x.second+max(x.first,y.second);
	
	return ans1<ans2;
}

int main(){
	int n;
	scanf("%d",&n);
	
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		
		v.emplace_back(make_pair(x,0));
	}
	
	for(int i=0;i<n;i++){
		scanf("%d",&v[i].second);
	}
	
	sort(v.begin(),v.end(),cmp);
	
	int m=v.size(),asum=0,ans=0;
	for(int i=0;i<m;i++){
		asum+=v[i].first;
		ans=max(ans,asum)+v[i].second;
	}
	
	printf("%d\n",ans);
	return 0;
}
