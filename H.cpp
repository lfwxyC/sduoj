#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){	
	int sum=0;
	string s;

	while(getline(cin,s)){
		if(s.length()==0){
			break;
		}
		
		stringstream ss;
		ss<<s;
		int i;
		
		while(ss>>i){
			sum+=i;
		}
		
		printf("%d\n",sum);
		sum=0;
	}
	
	return 0;
}
