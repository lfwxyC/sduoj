#include<cstdio>

int main(){	
	int n,x,count=0;
	scanf("%d%d",&n,&x);
	
	int a[n];
	for(int i=0;i<n;i++){
		int b;
		scanf("%d",&b);
		
		if(b!=x){
			a[count]=b;
			count++;
		}
	}
	
	for(int i=0;i<count;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}
