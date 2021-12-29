#include<cstdio>

int main(){	
	int n,sum=0;
	scanf("%d",&n);
	
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	
	for(int i=0;i<n;i++){
		sum+=a[i]*b[i];
	}
	
	if(sum==0){
		printf("Yes");
	}else{
		printf("No");
	}
	
	return 0;
}
