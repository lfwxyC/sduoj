#include<bits/stdc++.h>
using namespace std;

set<char> yuanyin={'a','e','i','o','u'}; // Ԫ�� 

int main(){
	int n,cnt=0,ans=0;
	string s;
	cin>>n>>s;
	
	for(int i=0;i<n;i++){
		// ��Ԫ���򳤶�+1 
		if(yuanyin.find(s[i]) != yuanyin.end()){
			cnt++;
			ans=max(ans,cnt);
		}
		// ����Ԫ���򳤶���0 
		else{
			cnt=0;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
