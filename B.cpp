#include<bits/stdc++.h>
using namespace std;

char yuanyin[]={'a','e','i','o','u'};

bool check(char c){
	for(int i=0;i<5;i++){
		if(c==yuanyin[i]){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	string s,ans;
	bool flag=true;
	cin>>n>>s;
	
	for(int i=0;i<n;i++){
		// ���ǵ�һ��Ԫ�������s 
		if(check(s[i])&&flag){
			ans+=s[i];
			flag=false;
		}
		
		// ������Ԫ�������s 
		if(check(s[i])==false){
			ans+=s[i];
			flag=true;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
