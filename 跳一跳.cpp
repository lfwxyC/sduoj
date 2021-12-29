#include<cstdio>

int main(){
	int jump,score=0,lastScore=1; // lastScore: 记录上一次得分 
	
	while(~scanf("%d",&jump)){
		// 游戏结束 
		if(jump==0){
			break;
		}
		
		if(jump==1){
			score++;
			lastScore=1;
		}
		else if(jump==2){
			// 上次得分为1分或是本局的第一次跳跃 
			if(lastScore==1){
				score+=2;
				lastScore=2;
			}
			else{
				score=score+lastScore+2; // 此次得分比上一次得分多两分 
				lastScore+=2;
			}
		}
	}
	
	printf("%d\n",score);
	
	return 0;
}
