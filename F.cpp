#include<cstdio>

int main(){	
	int n,sum=0;
	scanf("%d",&n);

	for(int j=0;j<n;j++){
		int m;
		scanf("%d",&m);
		
		int a[m];
		
		for(int i=0;i<m;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		
		printf("%d\n",sum);
		sum=0;
	}
	
	return 0;
}
