#include<bits/stdc++.h>
using namespace std;

int par[100010];

int find(int x){ // ����x�����ĸ����鼯 
	if(par[x]==x){
		return x;
	}
	return par[x]=find(par[x]);
}

bool unite(int x,int y){ // ���������鼯�ϲ� 
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
	
	// ��ʼ�����鼯 
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
	
	int ans=n-1; // ��ʼ��Ҫ�޽�n-1��· 
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		
		// ���ϲ��ɹ����������һ��· 
		if(unite(a,b)){
			ans--;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
