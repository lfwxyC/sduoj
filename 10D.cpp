#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
const int maxn=1e6+10;
int n,s[maxn];

int lb(int x){
    return x&(-x);
}

int ask(int x){
    int res=0;

    for(int i=x;i>=1;i-=lb(i)){
        res+=s[i];
    }
    return res;
}

void upd(int x,int v){
    for(int i=x;i<=maxn;i+=lb(i)){
        s[i]+=v;
    }
}

int main(){
    priority_queue<pa,vector<pa>,greater<pa>> q;
    scanf("%d",&n);
    
    int ans[n];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);

        y++;
        q.emplace(make_pair(x,y)); // 按照第一个数的大小排序
        ans[i]=0;
    }
    
    for(int i=0;i<maxn;i++){
        s[i]=0;
    }

    while(!q.empty()){
        int y=q.top().second;
        q.pop();

        int cnt=ask(y); // 内存占用量比y小的程序数量

        upd(y,1); // 内存占用量为y的程序数量+1
        ans[cnt]++;
    }

    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}