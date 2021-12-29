#include<bits/stdc++.h>
using namespace std;

int cnt,k,n;
char a[70]; // ���n*n�����ӵ���״ 
bool row[10],col[10]; // ���ÿ��ÿ���Ƿ�ѡ 

void dfs(int kk,int x){
	// ѡ��k�����������ĸ��ӣ�������+1 
	if(kk==k){
		cnt++;
		return;
	}
	
	// �����������ƣ�ֱ�ӷ��� 
	if(x>=n*n||kk>k){
		return;
	}
	
	// ���ø��ӿ��Է������Ҹø����������о�δ�����ӣ���ѡ��ø��� 
	if(a[x]=='#'&&row[x/n]==false&&col[x%n]==false){
		// �ø����������в����ٷ����� 
		row[x/n]=true;
		col[x%n]=true;
		dfs(kk+1,x+1);
		
		// �ָ�����Ϊ��ʼ״̬ 
		row[x/n]=false;
		col[x%n]=false;
	}
	dfs(kk,x+1); // ��ѡ��ø��� 
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
