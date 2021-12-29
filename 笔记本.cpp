#include<bits/stdc++.h>
using namespace std;

void search(set<string> &v){ // 查找 
	string s;
	cin>>s;
	
	// 找到 
	if(v.find(s)!=v.end()){
		printf("found\n");
	}
	// 未找到，按顺序插入 
	else{
		v.insert(s);
		printf("write\n");
	}
	
}

void erase(set<string> &v){ // 删除 
	string s;
	cin>>s;
	
	// 找到后删除 
	if(v.find(s)!=v.end()){
		v.erase(s);
		printf("erased\n");
	}
	// 未找到 
	else{
		printf("not found\n");
	}
}

int main(){
	int m;
	scanf("%d",&m);
	
	set<string> v;
	for(int i=0;i<m;i++){
		int opt;
		scanf("%d",&opt);
		
		switch(opt){
			case 1:
				search(v);
				break;
			case 2:
				erase(v);
				break;
			case 3: // 升序输出所有单词 
				for(auto &j:v){
					cout<<j<<" ";
				}
				printf("\n");
				break;
		}
	}
	
	return 0;
}
