#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=1e5+5;
int par[MAXN];

struct Edge{
	int u,v,w;
	
	bool operator<(const Edge &e)const{
		return w>e.w;
	}
}typedef Edge;

int find(int x){
	if(par[x]==x){
		return x;
	}
	return par[x]=find(par[x]);
}

bool unite(int x,int y){
	x=find(x);
	y=find(y);
	
	if(x==y){
		return false;
	}
	par[x]=y;
	return true;
}

int main(){
	int n,m,p;
	priority_queue<Edge> pq; // ��Ȩֵ��С�������С�� 
	scanf("%d%d%d",&n,&m,&p);
	
	// ȡ0Ϊ����Դ�㣬��������������һ��ȨֵΪp�ı� 
	for(int i=1;i<=n;i++){
		Edge e;
		e.u=0;
		e.v=i;
		e.w=p;
		pq.push(e);
	}
	
	for(int i=0;i<m;i++){
		Edge e;
		scanf("%d%d%d",&e.u,&e.v,&e.w);
		
		pq.push(e);
	}
	
	for(int i=0;i<=n;i++){
		par[i]=i;
	}
	
	int cnt=0;
	LL ans=0;
	// ����С������ 
	while(!pq.empty()&&cnt<n){
		Edge e=pq.top();
		pq.pop();
		
		if(unite(e.u,e.v)){
			ans+=e.w;
			cnt++;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
