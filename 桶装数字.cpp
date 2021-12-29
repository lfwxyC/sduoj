#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	vector<int> v[n];
	for(int i=0;i<m;i++){
		int number,table; // number:数字，table:桶号 ，从1开始 
		scanf("%d%d",&number,&table);
		
		v[table-1].push_back(number);
	}
	
	// 升序输出每个桶中的数字 
	for(int i=0;i<n;i++){
		sort(v[i].begin(),v[i].end());
		for(int j:v[i]){
			printf("%d ",j);
		}
		printf("\n");
	}
	
	return 0;
}
