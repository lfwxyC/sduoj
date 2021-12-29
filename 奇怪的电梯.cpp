#include<bits/stdc++.h>
using namespace std;

void bfs(int k[],int N,int A,int B){
	queue<int> q;
	q.push(A);
	int count[N+1]; // 记录移动的次数 
	bool vis[N+1];
	
	for(int i=1;i<=N;i++){
		vis[i]=false;
	}
	
	count[A]=0;
	vis[A]=true;
	
	while(!q.empty()){
		int x=q.front();
		q.pop();
		
		// 到达B层，停止循环 
		if(x==B){
			printf("%d\n",count[B]);
			return;
		}
		
		// UP
		if(x+k[x]<=N&&vis[x+k[x]]==false){
			q.push(x+k[x]);
			vis[x+k[x]]=true;
			count[x+k[x]]=count[x]+1;
		}
		
		// DOWN
		if(x-k[x]>0&&vis[x-k[x]]==false){
			q.push(x-k[x]);
			vis[x-k[x]]=true;
			count[x-k[x]]=count[x]+1;
		}
	}
	
	// 不能到达B层 
	printf("-1\n");
}

int main(){
	int N;
	
	while(~scanf("%d",&N)){
		if(N==0){
			break;
		}
		
		int A,B;
		int k[N+1];
		scanf("%d%d",&A,&B);
		
		for(int i=1;i<=N;i++){
			scanf("%d",&k[i]);
		}
		
		bfs(k,N,A,B);
	}
	
	return 0;
}
