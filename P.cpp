#include<cstdio>
#include<cmath>

int main(){	
	int a,b,h,m;
	scanf("%d%d%d%d",&a,&b,&h,&m);
	
	double hour=h*30.0+m*0.5;
	double degree=fabs(hour-m*6.0); // 求浮点数绝对值用fabs 
	double distance=a*a+b*b-2.0*a*b*cos(degree*M_PI/180.0);
	
	printf("%.10f",pow(distance,0.5));
	
	return 0;
}
