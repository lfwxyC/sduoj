#include<bits/stdc++.h>
using namespace std;

// 牌 
struct{
	int number; // 大小 
	int color; // 花色 
}typedef Card;

class Hand{ // 一手牌
public:
	Hand(int a1,int b1,int a2,int b2);
	
	void reset();
	void add(int number,int color);
	void play();
	void output();
	
private:
	Card *card; // 五张牌 
	int size; // 牌数 
	int type[9]; // 牌型数 
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

Hand::Hand(int a1,int b1,int a2,int b2){ // 构造函数 
	card=new Card[5];
	
	this->a1=a1;
	this->b1=b1;
	this->a2=a2;
	this->b2=b2;
	
	for(int i=0;i<9;i++){ // 每种牌型数的初始值为0 
		type[i]=0;
	}
}

void Hand::reset(){ // 重置一手牌 
	size=2;
	
	card[0].number=a1;
	card[0].color=b1;
	card[1].number=a2;
	card[1].color=b2;
}

void Hand::add(int number,int color){ // 添加抽出的三张牌 
	card[size].number=number;
	card[size].color=color;
	size++;
}

void Hand::play(){ // 按低序号优先匹配牌型 
	if(type0()){ // 一旦匹配成功则停止 
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
	
	type[8]++; // 要不起 
}

void Hand::output(){ // 输出牌型数 
	for(int i=0;i<9;i++){
		printf("%d ",type[i]);
	}
	printf("\n");
}

bool Hand::type0(){ // 同花顺 
	// 从小到大排序 
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(card[j].number>card[j+1].number){
				swap(card[j],card[j+1]);
			}
		}
	}

	// 判断花色 
	for(int i=1;i<5;i++){
		if(card[0].color!=card[i].color){
			return false;
		}
	}
	
	// 判断顺子 
	for(int i=0;i<4;i++){
		if((card[i].number+1)!=card[i+1].number){
			return false;
		}
	}
	type[0]++;
	return true;
}

bool Hand::type1(){ // 炸弹 
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

bool Hand::type2(){ // 三带二 
	// 此时五张牌已经排好顺序
	// 1.前三张带后两张 
	if(card[0].number==card[1].number&&card[0].number==card[2].number&&card[3].number==card[4].number){
		type[2]++;
		return true;
	} 
	// 2.后三张带前两张 
	else if(card[0].number==card[1].number&&card[2].number==card[3].number&&card[2].number==card[4].number){
		type[2]++;
		return true;
	}
	return false;
}

bool Hand::type3(){ // 同花 
	for(int i=1;i<5;i++){
		if(card[0].color!=card[i].color){
			return false;
		}
	}
	type[3]++;
	return true;
}

bool Hand::type4(){ // 顺子 
	for(int i=0;i<4;i++){
		if((card[i].number+1)!=card[i+1].number){
			return false;
		}
	}
	type[4]++;
	return true;
}

bool Hand::type5(){ // 三条 
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

bool Hand::type6(){ // 两对
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

bool Hand::type7(){ // 一对 
	for(int i=0;i<4;i++){
		if(card[i].number==card[i+1].number){
			type[7]++;
			return true;
		}
	}
	return false;
}

void combination(int n,Card card[],Hand &hand){ // 从n张牌中抽3张 
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
	
	// 初始化每张牌的大小和花色 
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if((a1==i&&b1==j)||(a2==i&&b2==j)){ // 跳过已经拿走的2张 
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
