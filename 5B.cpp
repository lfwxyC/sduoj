#include<bits/stdc++.h>
using namespace std;

// �ж�26����ĸ�Ƿ�ȫ������ 
bool check(int cnt[]){
	for(int i=0;i<26;i++){
		if(cnt[i]==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	string s;
	cin>>n>>s;
	
	int ll=0,rr=25,ans=n;
	int cnt[26];
	
	for(int i=0;i<26;i++){
		cnt[i]=0;
	}
	
	for(int i=0;i<26;i++){
		cnt[s[i]-'A']++;
	}
	
	while(rr<n){
		if(check(cnt)){ // ������������¼�� 
			ans=min(ans,rr-ll+1);
			cnt[s[ll]-'A']--;
			ll++;
		}else{
			rr++;
			cnt[s[rr]-'A']++;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
