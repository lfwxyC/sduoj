#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=1e5+5;

LL length[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void addEdge(int u,int v){ // 添加双向边 
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void dfs(int u){
	int n=G[u].size();
	
	for(int i=0;i<n;i++){
		if(!vis[G[u][i]]){
			vis[G[u][i]]=true;
			length[G[u][i]]=length[u]+1;
			dfs(G[u][i]);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		length[i]=0;
		vis[i]=false;
	}
	
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		
		addEdge(a,b);
	}
	
	int begin=0,end=0;
	LL maxLength=0;
	vis[1]=true;
	
	// 对1做dfs,找到距离1最远的点，即为直径的起点 
	dfs(1);
	for(int i=1;i<=n;i++){
		if(maxLength<length[i]){
			maxLength=length[i];
			begin=i;
		}
		
		length[i]=0;
		vis[i]=false;
	}
	
	// 对起点做bfs,找到直径的终点，同时记录起点到其它各点的距离 
	vis[begin]=true;
	dfs(begin);
	maxLength=0;
	
	LL ans[n+1];
	for(int i=1;i<=n;i++){
		if(maxLength<length[i]){
			maxLength=length[i];
			end=i;
		}
		
		ans[i]=length[i];
		length[i]=0;
		vis[i]=false;
	}
	
	// 对终点做bfs,记录终点到其他各点的距离 
	vis[end]=true;
	dfs(end);
	
	// 取各点距起点和终点的最大值 
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],length[i]);
		printf("%lld ",ans[i]);
	}
	
	return 0;
}
