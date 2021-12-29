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
	
	// 剩余小朋友人数大于1时游戏继续 
	while(q.size()>1){
		int x=q.front();
		q.pop();
		
		// 判断报的数是否为k的倍数或末位数为k 
		if(number%k!=0&&number%10!=k){
			q.push(x);
		}
		number++;
	}
	
	printf("%d\n",q.front());
	q.pop();
	
	return 0;
}
