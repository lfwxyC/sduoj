#include<cstdio>

int main(){
	int n,bottle,result=0;
	scanf("%d",&n);
	
	// Âò5ËÍ2 
	bottle=n/50;
	result+=bottle*7;
	
	// Âò3ËÍ1
	n=n-bottle*50;
	bottle=n/30;
	result+=bottle*4;
	
	// Ê£ÏÂµÄÇ®Âò1Æ¿»ò2Æ¿
	n=n-bottle*30;
	bottle=n/10;
	result+=bottle; 
	
	printf("%d",result); 
	
	return 0;
}
