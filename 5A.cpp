#include<bits/stdc++.h>
using namespace std;

// 判断26个字母是否全部存在 
bool check(int cnt[]){
	for(int i=0;i<26;i++){
		if(cnt[i]==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	string s;
	
	cin>>n>>s>>m;
	
	int ll=0,rr=25;
	int cnt[26];
	map<int,int> edge;
	
	for(int i=0;i<26;i++){
		cnt[i]=0;
	}
	
	for(int i=0;i<26;i++){
		cnt[s[i]-'A']++;
	}
	
	while(rr<n){
		// 26个字母全部存在，记录左端点对应的最小右端点，移动ll 
		if(check(cnt)){
			edge[ll]=rr;
			cnt[s[ll]-'A']--; // 当前ll被移出 
			ll++;
		}
		// 当前段不满足条件，移动rr 
		else{
			rr++;
			cnt[s[rr]-'A']++;
		}
	}
	
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		
		if(edge[l-1]&&edge[l-1]<=r-1){ // 当右端点大于等于l对应的最小右端点时满足条件 
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
