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
		// 26����ĸȫ�����ڣ���¼��˵��Ӧ����С�Ҷ˵㣬�ƶ�ll 
		if(check(cnt)){
			edge[ll]=rr;
			cnt[s[ll]-'A']--; // ��ǰll���Ƴ� 
			ll++;
		}
		// ��ǰ�β������������ƶ�rr 
		else{
			rr++;
			cnt[s[rr]-'A']++;
		}
	}
	
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		
		if(edge[l-1]&&edge[l-1]<=r-1){ // ���Ҷ˵���ڵ���l��Ӧ����С�Ҷ˵�ʱ�������� 
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
