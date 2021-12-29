#include<cstdio>

int main(){	
	float a,b;

	while(~scanf("%f%f",&a,&b)){
		float discount=(a-b)/a*100.0;
		
		printf("%.3f\n",discount);
	}
	
	return 0;
}
