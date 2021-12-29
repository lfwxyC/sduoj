#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = -1e9;
int n,m;
double a[maxn], sum[maxn];

bool check(double v) {
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i] - v;
	}
	
	double sum_max = inf, pre_min = 0;
	for (int i = m; i <= n ; i++) {	
		pre_min = min(pre_min, sum[i - m]);
		sum_max = max(sum_max, sum[i] - pre_min);
		
		if (sum_max >= 0) return true;
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	
	double lo=2000,hi=0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		
		lo=min(lo,a[i]);
		hi=max(hi,a[i]);
	}
	
	while(hi-lo>1e-6){
		double mid=(lo+hi)/2; // 平均值，若存在一段长度大于k的数的平均值大于mid, 则该平均值满足条件 
		
		// 当前平均值满足条件，寻找更大的平均值 
		if(check(mid)){
			lo=mid;
		}
		// 不满足条件，减小平均值 
		else{
			hi=mid;
		} 
	}
	
	int ans=hi*1000;
	printf("%d\n",ans);
	return 0;
}
