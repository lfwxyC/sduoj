#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	vector<int> v[n];
	for(int i=0;i<m;i++){
		int number,table; // number:���֣�table:Ͱ�� ����1��ʼ 
		scanf("%d%d",&number,&table);
		
		v[table-1].push_back(number);
	}
	
	// �������ÿ��Ͱ�е����� 
	for(int i=0;i<n;i++){
		sort(v[i].begin(),v[i].end());
		for(int j:v[i]){
			printf("%d ",j);
		}
		printf("\n");
	}
	
	return 0;
}
