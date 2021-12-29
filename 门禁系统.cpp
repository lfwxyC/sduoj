#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n]; // 存放来访记录 
	map<int,int> mp; // key:读者编号,value:出现次数 
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
		printf("%d ",mp[a[i]]);
	}
	
	return 0;
}
