#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int a[n];
	deque<int> d(k);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++){
		// ������������ 
		while(!d.empty()&&d.front()<=i-k){ // �±겻��k��Ԫ����ʱ���� 
			d.pop_front();
		}
		while(!d.empty()&&a[d.back()]>a[i]){ // Ҫ��ӵ�Ԫ�ش��ڶ�βԪ��ʱ����βԪ�س��� 
			d.pop_back();
		}
		d.push_back(i);
		
		if(i>=k-1){
			printf("%d ",a[d.front()]); // ����Ԫ��Ϊ��Сֵ 
		}
	}
	printf("\n");
	
	// ��ն��� 
	while(!d.empty()){
		d.pop_front();
	}
	
	for(int i=0;i<n;i++){
		// �����ݼ����� 
		while(!d.empty()&&d.front()<=i-k){
			d.pop_front();
		}
		while(!d.empty()&&a[d.back()]<a[i]){
			d.pop_back();
		}
		d.push_back(i);
		
		if(i>=k-1){
			printf("%d ",a[d.front()]); // ����Ԫ��Ϊ���ֵ 
		}
	}
	printf("\n");
	
	return 0;
}
