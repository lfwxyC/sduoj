#include<cstdio>
#include<algorithm>
using namespace std;

int g1(int x){ // Ωµ–Ú≈≈–Ú 
	int a[9];
	int n=0,b=1;
	
	while(x){
		a[n]=x%10;
		x/=10;
		n++;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		x+=a[i]*b;
		b*=10;
	}
	return x;
}

int g2(int x){ // …˝–Ú≈≈–Ú 
	int a[9];
	int n=0,b=1;
	
	while(x){
		a[n]=x%10;
		x/=10;
		n++;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		x+=a[i]*b;
		b*=10;
	}
	return x;
}

int f(int x){
	return g1(x)-g2(x);
}

int main(){	
	int n,k;
	scanf("%d%d",&n,&k);
	
	int a[k+1];
	a[0]=n;
	for(int i=1;i<=k;i++){
		a[i]=f(a[i-1]);
	}
	
	printf("%d",a[k]);
	
	return 0;
}
