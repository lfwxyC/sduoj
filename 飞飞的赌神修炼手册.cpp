#include<bits/stdc++.h>
using namespace std;

struct{
	int number;
	int color;
}typedef Card;

class Hand{ // 一手牌
public:
	Hand(int a1,int b1,int a2,int b2);
	
	void setSize();
	void add(int number,int color);
	void play();
	void output();
	
	void test();
	
private:
	Card *card;
	int size;
	int type[9];
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

Hand::Hand(int a1,int b1,int a2,int b2){
	card=new Card[5];
	
	this->a1=a1;
	this->b1=b1;
	this->a2=a2;
	this->b2=b2;
	
	for(int i=0;i<9;i++){
		type[i]=0;
	}
}

void Hand::test(){
	for(int i=0;i<5;i++){
		cout<<card[i].number<<" ";
	}
	cout<<endl;
}

void Hand::setSize(){
	size=2;
	card[0].number=a1;
	card[0].color=b1;
	card[1].number=a2;
	card[1].color=b2;
}

void Hand::add(int number,int color){
	card[size].number=number;
	card[size].color=color;
	size++;
}

void Hand::play(){
	if(type0()){
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
	
	type[8]++;
}

void Hand::output(){
	for(int i=0;i<9;i++){
		printf("%d ",type[i]);
	}
	printf("\n");
}

bool Hand::type0(){ // 同花顺 
	//test();

	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(card[j].number>card[j+1].number){
				swap(card[j],card[j+1]);
			}
		}
	}

	for(int i=1;i<5;i++){
		if(card[0].color!=card[i].color){
			return false;
		}
	}
	
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

void dfs(int num,int len,int n,int a[],Card card[],Hand &hand){
	if(len==3){//选全m个数 
		hand.setSize();
		for(int i=1;i<=3;i++){
			hand.add(card[a[i]-1].number,card[a[i]-1].color);
			//cout<<card[a[i]-1].number<<" ";
		}
		//cout<<endl;
		hand.play();
		return;
	}
	if(num==n){//没有选全m个数，但是数已经超过n，return； 
		return ;
	}
	for(int i=num+1;i<=n;i++){//寻找num后面的数字 
		a[++len]=i;//选进 
		dfs(i,len,n,a,card,hand);
		len--;//踢出 
	}
	return ;
}

int main(){
	int a,b,a1,b1,a2,b2;
	scanf("%d%d%d%d%d%d",&a,&b,&a1,&b1,&a2,&b2);
	
	int len=a*b,k=0;
	Card card[len];
	Hand hand(a1,b1,a2,b2);
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if((a1==i&&b1==j)||(a2==i&&b2==j)){
				continue;
			}else{
				card[k].number=i;
				card[k].color=j;
				k++;
			}
		}
	}
	
	int test[4];
	dfs(0,0,len-2,test,card,hand);
	hand.output();
	return 0;	
}
