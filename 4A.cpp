#include<bits/stdc++.h>
using namespace std;

// 路段l到r之间至少有k个垃圾桶 
struct Road{
	int l,r,k;
	
	bool operator<(const Road &road)const{
		return r>road.r;
	}
}typedef Road;

int main(){
	int n,m,ans=0;
	priority_queue<Road> p; // 按r从小到大的顺序存放 
	scanf("%d%d",&n,&m);
	
	bool a[n+1]; // 记录是否摆放垃圾桶 
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
		
		// 计算l到r已经摆放了多少个垃圾桶 
		int cnt=0;
		for(int i=now.l;i<=now.r;i++){
			if(a[i]){
				cnt++;
			}
		}
		
		// 垃圾桶数量不够，从右往左开始摆放 
		if(cnt<now.k){
			int x=now.k-cnt,index=now.r; // x:还需摆放的垃圾桶数量 
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
