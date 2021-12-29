#include<bits/stdc++.h>
using namespace std;

int par[100010];

int find(int x){ // 查找x属于哪个并查集 
	if(par[x]==x){
		return x;
	}
	return par[x]=find(par[x]);
}

bool unite(int x,int y){ // 将两个并查集合并 
	x=find(x);
	y=find(y);
	
	if(x==y){
		return false;
	}
	
	par[x]=y;
	return true;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	// 初始化并查集 
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
	
	int ans=n-1; // 初始需要修建n-1条路 
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		
		// 若合并成功则可以少修一条路 
		if(unite(a,b)){
			ans--;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
