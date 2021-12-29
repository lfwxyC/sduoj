#include<cstdio>
#include<cmath>

int main(){
	int n,count=0;
	scanf("%d",&n);
	
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(abs(a[i]-a[j])==1){
				count++;
			}
		}
	}
	
	printf("%d",count);
	return 0;
}
