#include<cstdio>

int main(){	
	int n,sum=0;

	while(~scanf("%d",&n)){
		int a[n];
		
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		
		printf("%d\n",sum);
		sum=0;
	}
	
	return 0;
}
