#include<cstdio>

int main(){
	int jump,score=0,lastScore=1; // lastScore: ��¼��һ�ε÷� 
	
	while(~scanf("%d",&jump)){
		// ��Ϸ���� 
		if(jump==0){
			break;
		}
		
		if(jump==1){
			score++;
			lastScore=1;
		}
		else if(jump==2){
			// �ϴε÷�Ϊ1�ֻ��Ǳ��ֵĵ�һ����Ծ 
			if(lastScore==1){
				score+=2;
				lastScore=2;
			}
			else{
				score=score+lastScore+2; // �˴ε÷ֱ���һ�ε÷ֶ����� 
				lastScore+=2;
			}
		}
	}
	
	printf("%d\n",score);
	
	return 0;
}
