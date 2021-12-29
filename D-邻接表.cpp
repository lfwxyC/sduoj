#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=1e5+5;

LL length[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void addEdge(int u,int v){ // ���˫��� 
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
	
	// ��1��dfs,�ҵ�����1��Զ�ĵ㣬��Ϊֱ������� 
	dfs(1);
	for(int i=1;i<=n;i++){
		if(maxLength<length[i]){
			maxLength=length[i];
			begin=i;
		}
		
		length[i]=0;
		vis[i]=false;
	}
	
	// �������bfs,�ҵ�ֱ�����յ㣬ͬʱ��¼��㵽��������ľ��� 
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
	
	// ���յ���bfs,��¼�յ㵽��������ľ��� 
	vis[end]=true;
	dfs(end);
	
	// ȡ����������յ�����ֵ 
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],length[i]);
		printf("%lld ",ans[i]);
	}
	
	return 0;
}
