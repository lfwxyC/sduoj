#include<bits/stdc++.h>
using namespace std;

#define LL long long

void add(int &opId,queue<pair<LL,LL> > &q){ // ��һ��ϲ����Ϊu���´��� 
	LL u;
	scanf("%lld",&u);
	
	int qsize=q.size();
	bool flag=true; // ��u������flag=false,���򿪶Ի��� 
	
	// �������У��Ѷ���Ԫ�ط�����β����ɾ������Ԫ�� 
	for(int i=0;i<qsize;i++){		
		if(u==q.front().first){
			printf("OpId #%d: same likeness.\n",opId);
			flag=false;
		}
		
		q.push(q.front());
		q.pop();
	}
	
	if(flag){
		q.push(make_pair(u,0)); // ���¶Ի��򣬲�������β���Ի���Ϊ0 
		printf("OpId #%d: success.\n",opId);
	}
}

void close(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // �ص�ϲ����Ϊu�Ĵ��� 
	LL u;
	scanf("%lld",&u);
	
	int qsize=q.size();
	bool flag=true;
	for(int i=0;i<qsize;i++){
		if(u==q.front().first){
			printf("OpId #%d: close %lld with %lld.\n",opId,u,q.front().second);
			q.pop();
			flag=false;
			
			// ���ر��ö�����������topNum 
			if(u==topNum){
				topNum=-1;
			}
		}
		else{
			q.push(q.front());
			q.pop();
		}
	}
	
	if(flag){
		printf("OpId #%d: invalid likeness.\n",opId);
	}
}

void chat(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // �Ͷ��㴰�ڽ���w�仰 
	LL w;
	scanf("%lld",&w);
	
	if(q.empty()){
		printf("OpId #%d: empty.\n",opId);
		return;
	}
	
	// ���зǿ� 
	if(topNum==-1){ // û���ö����ڣ�����״������� 
		q.front().second+=w;
	}
	
	// ���ö��������� 
	else{
		int qsize=q.size();
		
		// �������У�Ѱ���ö����� 
		for(int i=0;i<qsize;i++){
			if(topNum==q.front().first){
				q.front().second+=w;
			}
			q.push(q.front());
			q.pop();
		}
	}
	printf("OpId #%d: success.\n",opId);
}

void rotate(int &opId,queue<pair<LL,LL> > &q,int x){ // ����x�����ڷ��ڶ��� 
	int qsize=q.size();
	
	if(x>qsize||x<1){
		printf("OpId #%d: out of range.\n",opId);
		return;
	}
	
	pair<LL,LL> a[qsize];
	int count=0;
	
	// �������У�ɾ����x������֮��Ĵ��ڣ������������ 
	for(int i=1;i<=qsize;i++){
		if(i!=x){
			a[count]=q.front();
			count++;
			q.pop();
		}
		
		// ��x���������ڶ����� 
		else{
			q.push(q.front());
			q.pop();
		}
	}
	
	// �������еĴ��ڰ�˳�������� 
	for(int i=0;i<count;i++){
		q.push(a[i]);
	}
	
	printf("OpId #%d: success.\n",opId);
}

void prior(int &opId,queue<pair<LL,LL> > &q){ // ��ϲ�������Ĵ��ڷ��ڶ��� 
	if(q.empty()){
		printf("OpId #%d: empty.\n",opId);
		return;
	}
	
	// ���зǿ� 
	int maxId=1,qsize=q.size();
	LL maxNum=0;
	
	// �������У�Ѱ�����ϲ�����ǵڼ������� 
	for(int i=1;i<=qsize;i++){
		if(maxNum<q.front().first){
			maxNum=q.front().first;
			maxId=i;
		}
		q.push(q.front());
		q.pop();
	}
	 
	rotate(opId,q,maxId); // �����ϲ���ȵĴ��ڷ������� 
}

void choose(int &opId,queue<pair<LL,LL> > &q){ // ��ϲ����Ϊu�Ĵ��ڷ��ڶ��� 
	LL u;
	int index=1;
	scanf("%lld",&u);
	
	// �������У�Ѱ��ϲ����Ϊu���ǵڼ�������
	int qsize=q.size();
	bool flag=true;
	for(int i=1;i<=qsize;i++){
		if(u==q.front().first){
			index=i;
			flag=false;
		}
		q.push(q.front());
		q.pop();
	}
	
	if(flag){
		printf("OpId #%d: invalid likeness.\n",opId);
	}else{
		rotate(opId,q,index);
	}
}

void top(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // ��ϲ����Ϊu�Ĵ����ö� 
	LL u;
	scanf("%lld",&u);
	
	// �������У��ҵ�ϲ����Ϊu�Ĵ���
	int qsize=q.size();
	bool flag=true;
	for(int i=0;i<qsize;i++){
		if(u==q.front().first){
			topNum=u;
			printf("OpId #%d: success.\n",opId);
			flag=false;
		}
		q.push(q.front());
		q.pop();
	}
	
	if(flag){
		printf("OpId #%d: invalid likeness.\n",opId);
	}
}

void untop(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // ȡ���ö� 
	if(topNum==-1){
		printf("OpId #%d: no such person.\n",opId);
		return;
	}
	
	topNum=-1;
	printf("OpId #%d: success.\n",opId);
}

void bye(int &opId,queue<pair<LL,LL> > &q,LL &topNum){
	// �������ö��������Ⱥ��ö�˵bye 
	if(topNum!=-1){
		int qsize=q.size();
		
		for(int i=0;i<qsize;i++){
			if(topNum==q.front().first&&q.front().second){
				printf("OpId #%d: Bye %lld: %lld.\n",opId,topNum,q.front().second);
				opId++;
				q.pop(); // ˵bye��ֱ�ӴӶ�����ɾ���ô��� 
			}else{
				q.push(q.front());
				q.pop();
			}
		}
	}
	
	// ���κ���������˵bye 
	while(!q.empty()){
		if(q.front().second){
			printf("OpId #%d: Bye %lld: %lld.\n",opId,q.front().first,q.front().second);
			opId++;
		}
		q.pop();
	}
}

int main(){
	int T;  
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		
		queue<pair<LL,LL> > q;
		LL topNum=-1; // �ö����ڵ�ϲ���ȣ�û���ö�����ʱΪ-1 
		int opId=1; // ��־���
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			
			if(s=="Add"){
				add(opId,q);
			}
			else if(s=="Close"){
				close(opId,q,topNum);
			}
			else if(s=="Chat"){
				chat(opId,q,topNum);
			}
			else if(s=="Rotate"){
				int x;
				scanf("%d",&x);
				rotate(opId,q,x);
			}
			else if(s=="Prior"){
				prior(opId,q);
			}
			else if(s=="Choose"){
				choose(opId,q);
			}
			else if(s=="Top"){
				top(opId,q,topNum);
			}
			else if(s=="Untop"){
				untop(opId,q,topNum);
			}
			opId++;			
		}
		bye(opId,q,topNum);
	}
	
	return 0;
}
