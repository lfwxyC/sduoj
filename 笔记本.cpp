#include<bits/stdc++.h>
using namespace std;

void search(set<string> &v){ // ���� 
	string s;
	cin>>s;
	
	// �ҵ� 
	if(v.find(s)!=v.end()){
		printf("found\n");
	}
	// δ�ҵ�����˳����� 
	else{
		v.insert(s);
		printf("write\n");
	}
	
}

void erase(set<string> &v){ // ɾ�� 
	string s;
	cin>>s;
	
	// �ҵ���ɾ�� 
	if(v.find(s)!=v.end()){
		v.erase(s);
		printf("erased\n");
	}
	// δ�ҵ� 
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
			case 3: // ����������е��� 
				for(auto &j:v){
					cout<<j<<" ";
				}
				printf("\n");
				break;
		}
	}
	
	return 0;
}
