#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int a[n];
	LL total=0; // 石头的总重量 
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		total+=a[i];
	}
	
	LL hi=total+1,lo=0,ans=1e9,mid,y=0;
	LL vsum[n];
	
	while(lo<=hi){
		int index=0;
		vsum[index]=0;
		mid=(lo+hi)/2; // 每组石头重量和的最大值 
			
		for(int i=0;i<n;i++){
			if(vsum[index]+a[i]>mid){
				index++;
				if(index>=n){
					break;
				}else{
					vsum[index]=0;
				}
			}
			
			vsum[index]+=a[i];
		}
		
		// 刚好分了m组，记录答案
		if(index==m-1){
			y=*max_element(vsum,vsum+m);
			ans=min(ans,y);
		}
		// 分了超过m组，mid过小，增大mid 
		if(index>=m){
			lo=mid+1;
		}
		// 分不到m组，减小mid 
		else{
			hi=mid-1;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
