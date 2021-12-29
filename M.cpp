#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){	
	string s;
	cin>>s;
	int i,n=s.length();
	
	for(i=0;i<n-1;i+=2){
		if(s[i]<'a'||s[i]>'z'||s[i+1]<'A'||s[i+1]>'Z'){
			printf("No");
			break;
		}
	}
	
	if(i>=n-1){
		printf("Yes");
	}
	return 0;
}
