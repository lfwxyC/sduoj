#include<bits/stdc++.h>
using namespace std;

#define LL long long

void add(int &opId,queue<pair<LL,LL> > &q){ // 打开一个喜爱度为u的新窗口 
	LL u;
	scanf("%lld",&u);
	
	int qsize=q.size();
	bool flag=true; // 若u存在则flag=false,不打开对话框 
	
	// 遍历队列，把队首元素放至队尾，再删除队首元素 
	for(int i=0;i<qsize;i++){		
		if(u==q.front().first){
			printf("OpId #%d: same likeness.\n",opId);
			flag=false;
		}
		
		q.push(q.front());
		q.pop();
	}
	
	if(flag){
		q.push(make_pair(u,0)); // 打开新对话框，插入至队尾，对话数为0 
		printf("OpId #%d: success.\n",opId);
	}
}

void close(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // 关掉喜爱度为u的窗口 
	LL u;
	scanf("%lld",&u);
	
	int qsize=q.size();
	bool flag=true;
	for(int i=0;i<qsize;i++){
		if(u==q.front().first){
			printf("OpId #%d: close %lld with %lld.\n",opId,u,q.front().second);
			q.pop();
			flag=false;
			
			// 若关闭置顶窗口则重置topNum 
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

void chat(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // 和顶层窗口交流w句话 
	LL w;
	scanf("%lld",&w);
	
	if(q.empty()){
		printf("OpId #%d: empty.\n",opId);
		return;
	}
	
	// 队列非空 
	if(topNum==-1){ // 没有置顶窗口，与队首窗口聊天 
		q.front().second+=w;
	}
	
	// 与置顶窗口聊天 
	else{
		int qsize=q.size();
		
		// 遍历队列，寻找置顶窗口 
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

void rotate(int &opId,queue<pair<LL,LL> > &q,int x){ // 将第x个窗口放在队首 
	int qsize=q.size();
	
	if(x>qsize||x<1){
		printf("OpId #%d: out of range.\n",opId);
		return;
	}
	
	pair<LL,LL> a[qsize];
	int count=0;
	
	// 遍历队列，删除第x个窗口之外的窗口，存放在数组中 
	for(int i=1;i<=qsize;i++){
		if(i!=x){
			a[count]=q.front();
			count++;
			q.pop();
		}
		
		// 第x个窗口留在队列中 
		else{
			q.push(q.front());
			q.pop();
		}
	}
	
	// 把数组中的窗口按顺序插入队列 
	for(int i=0;i<count;i++){
		q.push(a[i]);
	}
	
	printf("OpId #%d: success.\n",opId);
}

void prior(int &opId,queue<pair<LL,LL> > &q){ // 将喜爱度最大的窗口放在队首 
	if(q.empty()){
		printf("OpId #%d: empty.\n",opId);
		return;
	}
	
	// 队列非空 
	int maxId=1,qsize=q.size();
	LL maxNum=0;
	
	// 遍历队列，寻找最大喜爱度是第几个窗口 
	for(int i=1;i<=qsize;i++){
		if(maxNum<q.front().first){
			maxNum=q.front().first;
			maxId=i;
		}
		q.push(q.front());
		q.pop();
	}
	 
	rotate(opId,q,maxId); // 把最大喜爱度的窗口放至队首 
}

void choose(int &opId,queue<pair<LL,LL> > &q){ // 将喜爱度为u的窗口放在队首 
	LL u;
	int index=1;
	scanf("%lld",&u);
	
	// 遍历队列，寻找喜爱度为u的是第几个窗口
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

void top(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // 将喜爱度为u的窗口置顶 
	LL u;
	scanf("%lld",&u);
	
	// 遍历队列，找到喜爱度为u的窗口
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

void untop(int &opId,queue<pair<LL,LL> > &q,LL &topNum){ // 取消置顶 
	if(topNum==-1){
		printf("OpId #%d: no such person.\n",opId);
		return;
	}
	
	topNum=-1;
	printf("OpId #%d: success.\n",opId);
}

void bye(int &opId,queue<pair<LL,LL> > &q,LL &topNum){
	// 若存在置顶窗口则先和置顶说bye 
	if(topNum!=-1){
		int qsize=q.size();
		
		for(int i=0;i<qsize;i++){
			if(topNum==q.front().first&&q.front().second){
				printf("OpId #%d: Bye %lld: %lld.\n",opId,topNum,q.front().second);
				opId++;
				q.pop(); // 说bye后直接从队列中删除该窗口 
			}else{
				q.push(q.front());
				q.pop();
			}
		}
	}
	
	// 依次和其它窗口说bye 
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
		LL topNum=-1; // 置顶窗口的喜爱度，没有置顶窗口时为-1 
		int opId=1; // 日志编号
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
