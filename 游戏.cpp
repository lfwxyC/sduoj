#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,number=1;
	queue<int> q;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++){
		q.push(i+1);
	}
	
	// ʣ��С������������1ʱ��Ϸ���� 
	while(q.size()>1){
		int x=q.front();
		q.pop();
		
		// �жϱ������Ƿ�Ϊk�ı�����ĩλ��Ϊk 
		if(number%k!=0&&number%10!=k){
			q.push(x);
		}
		number++;
	}
	
	printf("%d\n",q.front());
	q.pop();
	
	return 0;
}
