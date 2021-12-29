#include<bits/stdc++.h>
using namespace std;

// �� 
struct{
	int number; // ��С 
	int color; // ��ɫ 
}typedef Card;

class Hand{ // һ����
public:
	Hand(int a1,int b1,int a2,int b2);
	
	void reset();
	void add(int number,int color);
	void play();
	void output();
	
private:
	Card *card; // ������ 
	int size; // ���� 
	int type[9]; // ������ 
	int a1,b1,a2,b2;
	
protected:
	bool type0();
 	bool type1();
 	bool type2();
 	bool type3();
 	bool type4();
 	bool type5();
 	bool type6();
 	bool type7();
};

Hand::Hand(int a1,int b1,int a2,int b2){ // ���캯�� 
	card=new Card[5];
	
	this->a1=a1;
	this->b1=b1;
	this->a2=a2;
	this->b2=b2;
	
	for(int i=0;i<9;i++){ // ÿ���������ĳ�ʼֵΪ0 
		type[i]=0;
	}
}

void Hand::reset(){ // ����һ���� 
	size=2;
	
	card[0].number=a1;
	card[0].color=b1;
	card[1].number=a2;
	card[1].color=b2;
}

void Hand::add(int number,int color){ // ��ӳ���������� 
	card[size].number=number;
	card[size].color=color;
	size++;
}

void Hand::play(){ // �����������ƥ������ 
	if(type0()){ // һ��ƥ��ɹ���ֹͣ 
		return;
	}
	
	if(type1()){
		return;
	}
	
	
	if(type2()){
		return;
	}
	
	if(type3()){
		return;
	}
	
	if(type4()){
		return;
	}
	
	if(type5()){
		return;
	}
	
	if(type6()){
		return;
	}
	
	if(type7()){
		return;
	}
	
	type[8]++; // Ҫ���� 
}

void Hand::output(){ // ��������� 
	for(int i=0;i<9;i++){
		printf("%d ",type[i]);
	}
	printf("\n");
}

bool Hand::type0(){ // ͬ��˳ 
	// ��С�������� 
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(card[j].number>card[j+1].number){
				swap(card[j],card[j+1]);
			}
		}
	}

	// �жϻ�ɫ 
	for(int i=1;i<5;i++){
		if(card[0].color!=card[i].color){
			return false;
		}
	}
	
	// �ж�˳�� 
	for(int i=0;i<4;i++){
		if((card[i].number+1)!=card[i+1].number){
			return false;
		}
	}
	type[0]++;
	return true;
}

bool Hand::type1(){ // ը�� 
	if(card[0].number==card[1].number&&card[0].number==card[2].number&&card[0].number==card[3].number){
		type[1]++;
		return true;
	}
	else if(card[1].number==card[2].number&&card[1].number==card[3].number&&card[1].number==card[4].number){
		type[1]++;
		return true;
	}
	return false;
}

bool Hand::type2(){ // ������ 
	// ��ʱ�������Ѿ��ź�˳��
	// 1.ǰ���Ŵ������� 
	if(card[0].number==card[1].number&&card[0].number==card[2].number&&card[3].number==card[4].number){
		type[2]++;
		return true;
	} 
	// 2.�����Ŵ�ǰ���� 
	else if(card[0].number==card[1].number&&card[2].number==card[3].number&&card[2].number==card[4].number){
		type[2]++;
		return true;
	}
	return false;
}

bool Hand::type3(){ // ͬ�� 
	for(int i=1;i<5;i++){
		if(card[0].color!=card[i].color){
			return false;
		}
	}
	type[3]++;
	return true;
}

bool Hand::type4(){ // ˳�� 
	for(int i=0;i<4;i++){
		if((card[i].number+1)!=card[i+1].number){
			return false;
		}
	}
	type[4]++;
	return true;
}

bool Hand::type5(){ // ���� 
	if(card[0].number==card[1].number&&card[0].number==card[2].number){
		type[5]++;
		return true;
	}
	else if(card[1].number==card[2].number&&card[1].number==card[3].number){
		type[5]++;
		return true;
	}
	else if(card[2].number==card[3].number&&card[2].number==card[4].number){
		type[5]++;
		return true;
	}
	return false;
}

bool Hand::type6(){ // ����
	if(card[0].number==card[1].number){
		if(card[2].number==card[3].number||card[3].number==card[4].number){
			type[6]++;
			return true;
		}
	}
	else if(card[1].number==card[2].number&&card[3].number==card[4].number){
		type[6]++;
		return true;
	}
	return false;
}

bool Hand::type7(){ // һ�� 
	for(int i=0;i<4;i++){
		if(card[i].number==card[i+1].number){
			type[7]++;
			return true;
		}
	}
	return false;
}

void combination(int n,Card card[],Hand &hand){ // ��n�����г�3�� 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				hand.reset();
				hand.add(card[i].number,card[i].color);
				hand.add(card[j].number,card[j].color);
				hand.add(card[k].number,card[k].color);
				hand.play();
			}
		}
	}
}

int main(){
	int a,b,a1,b1,a2,b2;
	scanf("%d%d%d%d%d%d",&a,&b,&a1,&b1,&a2,&b2);
	
	int len=a*b,k=0;
	Card card[len];
	Hand hand(a1,b1,a2,b2);
	
	// ��ʼ��ÿ���ƵĴ�С�ͻ�ɫ 
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if((a1==i&&b1==j)||(a2==i&&b2==j)){ // �����Ѿ����ߵ�2�� 
				continue;
			}else{
				card[k].number=i;
				card[k].color=j;
				k++;
			}
		}
	}
	
	combination(len-2,card,hand);
	hand.output();
	return 0;	
}
