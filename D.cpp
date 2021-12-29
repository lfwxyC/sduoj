#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn=1e6;

int tot;
int head[maxn];
LL length[maxn],ans[maxn];
bool vis[maxn];

struct Edge{
	int u,v,nxt;
}Edges[maxn];

void addEdge(int u,int v){
	Edges[tot].u=u;
	Edges[tot].v=v;
	Edges[tot].nxt=head[u];
	head[u]=tot;
	tot++;
}

void dfs(int u){
	for(int i=head[u];i!=-1;i=Edges[i].nxt){
		if(!vis[Edges[i].v]){
			vis[Edges[i].v]=true;
			length[Edges[i].v]=length[u]+1;
			dfs(Edges[i].v);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		head[i]=-1;
		length[i]=0;
		vis[i]=false;
	}
	
	tot=0;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		
		addEdge(a,b);
		addEdge(b,a);
	}
	
	int begin=0,end=0;
	LL maxLength=0;
	vis[1]=true;
	
	dfs(1);
	for(int i=1;i<=n;i++){
		if(maxLength<length[i]){
			maxLength=length[i];
			begin=i;
		}
		
		length[i]=0;
		vis[i]=false;
	}
	
	vis[begin]=true;
	dfs(begin);
	maxLength=0;
	
	for(int i=1;i<=n;i++){
		if(maxLength<length[i]){
			maxLength=length[i];
			end=i;
		}
		
		ans[i]=length[i];
		length[i]=0;
		vis[i]=false;
	}
	
	vis[end]=true;
	dfs(end);
	
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],length[i]);
		printf("%lld ",ans[i]);
	}
	
	return 0;
}
