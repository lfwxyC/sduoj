#include<bits/stdc++.h>
using namespace std;

// ·��l��r֮��������k������Ͱ 
struct Road{
	int l,r,k;
	
	bool operator<(const Road &road)const{
		return r>road.r;
	}
}typedef Road;

int main(){
	int n,m,ans=0;
	priority_queue<Road> p; // ��r��С�����˳���� 
	scanf("%d%d",&n,&m);
	
	bool a[n+1]; // ��¼�Ƿ�ڷ�����Ͱ 
	for(int i=1;i<=n;i++){
		a[i]=false;
	}
	
	for(int i=0;i<m;i++){
		Road road;
		scanf("%d%d%d",&road.l,&road.r,&road.k);
		
		p.emplace(road);
	}
	
	while(!p.empty()){
		Road now=p.top();
		p.pop();
		
		// ����l��r�Ѿ��ڷ��˶��ٸ�����Ͱ 
		int cnt=0;
		for(int i=now.l;i<=now.r;i++){
			if(a[i]){
				cnt++;
			}
		}
		
		// ����Ͱ������������������ʼ�ڷ� 
		if(cnt<now.k){
			int x=now.k-cnt,index=now.r; // x:����ڷŵ�����Ͱ���� 
			ans+=x;
			
			while(x){
				while(a[index]){
					index--;
				}
				a[index]=true;
				index--;
				x--;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
