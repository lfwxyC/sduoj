#include<bits/stdc++.h>
using namespace std;

int cnt,k,n;
char a[70]; // 存放n*n个格子的形状 
bool row[10],col[10]; // 存放每行每列是否被选 

void dfs(int kk,int x){
	// 选了k个满足条件的格子，方案数+1 
	if(kk==k){
		cnt++;
		return;
	}
	
	// 超出条件限制，直接返回 
	if(x>=n*n||kk>k){
		return;
	}
	
	// 若该格子可以放棋子且该格子所在行列均未放棋子，则选择该格子 
	if(a[x]=='#'&&row[x/n]==false&&col[x%n]==false){
		// 该格子所在行列不能再放棋子 
		row[x/n]=true;
		col[x%n]=true;
		dfs(kk+1,x+1);
		
		// 恢复行列为初始状态 
		row[x/n]=false;
		col[x%n]=false;
	}
	dfs(kk,x+1); // 不选择该格子 
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		if(n==-1&&k==-1){
			break;
		}
		
		for(int i=0;i<n*n;i++){
				cin>>a[i];
		}
		
		for(int i=0;i<n;i++){
			row[i]=false;
			col[i]=false;
		}
		
		cnt=0;
		dfs(0,0);
		printf("%d\n",cnt);
	}
	
	return 0;
}
