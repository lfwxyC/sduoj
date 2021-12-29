#include<cstdio>
using namespace std;

int cnt,k,n;
int a[25];

bool prime(int n) // �ж����� 
{
    if (n==1) 
		return false;
    if (n==2) 
		return true;
			
	for(int i=2;i*i<=n;i++)
	   if (n%i==0) 
	   	return false;
	   	
	return true; 
}

void dfs(int sum,int kk,int x){
	// ���������������+1 
	if(kk==k&&prime(sum)){
		cnt++;
		return;
	}
	
	// �����������ƣ�ֱ�ӷ��� 
	if(x>=n||kk>k){
		return;
	}
	dfs(sum,kk,x+1); // ��ѡ��x 
	dfs(sum+a[x],kk+1,x+1); // ѡ��x 
}

int main(){
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	dfs(0,0,0);
	printf("%d\n",cnt);
	
	return 0;
}
