#include<cstdio>

int main(){
	int n,bottle,result=0;
	scanf("%d",&n);
	
	// ��5��2 
	bottle=n/50;
	result+=bottle*7;
	
	// ��3��1
	n=n-bottle*50;
	bottle=n/30;
	result+=bottle*4;
	
	// ʣ�µ�Ǯ��1ƿ��2ƿ
	n=n-bottle*30;
	bottle=n/10;
	result+=bottle; 
	
	printf("%d",result); 
	
	return 0;
}
