#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n]; // ������ü�¼ 
	map<int,int> mp; // key:���߱��,value:���ִ��� 
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
		printf("%d ",mp[a[i]]);
	}
	
	return 0;
}
