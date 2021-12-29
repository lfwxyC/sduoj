#include<bits/stdc++.h>
using namespace std;

#define LL long long

// 快速幂 
LL qpow(LL a,LL b,LL p){
	LL ans=1;
	
	for(a%=p;b;a=a*a%p,b>>=1){
		if(b&1){
			ans=ans*a%p;
		}
	}
	return ans;
}

int main(){
	int n,m;
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; // 100以内的质数 
	scanf("%d%d",&n,&m);
	
	LL a[n+1][25],d[n+2][25],cnt[25],sum[25]; // d是a的差分数组 
	for(int i=0;i<=n;i++){
		for(int j=0;j<25;j++){
			a[i][j]=0;
			d[i][j]=0;
		}
	}
	
	for(int i=0;i<25;i++){
		d[n+1][i]=0;
		cnt[i]=LLONG_MAX;
		sum[i]=0;
	}
	
	for(int i=0;i<m;i++){
		int l,r,c,b;
		scanf("%d%d%d%d",&l,&r,&c,&b);
		
		for(int j=0;j<25;j++){
			// 把c分解为质数 
			while(c%prime[j]==0){
				d[l][j]+=b;
				d[r+1][j]-=b;
				
				c/=prime[j];
			}
		}
	}
	
	// 计算a 
	for(int i=1;i<=n;i++){
		for(int j=0;j<25;j++){
			a[i][j] = a[i - 1][j] + d[i][j];
		}
	}
	
	// 计算每个质数的最小幂次 
	for(int j=0;j<25;j++){
		for(int i=1;i<=n;i++){
			cnt[j]=min(cnt[j],a[i][j]);
		}
	}
	
	int ans=1,p=1e9+7;
	for(int i=0;i<25;i++){
		LL y=qpow(prime[i],cnt[i],p);
		ans=(ans*y)%p;
	}
	
	printf("%d\n",ans);
	return 0;
}
