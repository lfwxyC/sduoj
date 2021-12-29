#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
int dcnt,scnt,n; //scnt:scc计数
int c[maxn],dfn[maxn]; // c[i]:i点所在scc编号,dfn[i]:dfs后序列第i个点
bool vis[maxn];
vector<int> G1[maxn],G2[maxn];

void dfs1(int x){
    vis[x]=true;
    for(auto y:G1[x]){
        if(!vis[y]){
            dfs1(y);
        }
    }
    dcnt++;
    dfn[dcnt]=x;
}

void dfs2(int x){
    c[x]=scnt;
    for(auto y:G2[x]){
        if(!c[y]){
            dfs2(y);
        }
    }
}

void kosaraju(){ //计算SCC
    dcnt=scnt=0;
    for(int i=1;i<=n;i++){
        c[i]=0;
        vis[i]=false;
    }

    // 第一遍dfs确定原图的逆后序序列
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    // 第二遍dfs在反图中按照逆后序序列进行遍历
    for(int i=n;i>=1;i--){
        if(!c[dfn[i]]){
            scnt++;
            dfs2(dfn[i]);
        }
    }
}

int main(){
    int m,ans=0;
    scanf("%d%d",&n,&m);

    int in_deg[n+1];
    for(int i=1;i<=n;i++){
        in_deg[i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);

        G1[x].emplace_back(y);
        G2[y].emplace_back(x);
    }

    kosaraju();

    // 缩点
    vector<int> scc[n+1];
    for(int i=1;i<=n;i++){
        int u=c[i];

        for(auto x:G1[i]){
            int v=c[x];

            if(u!=v){ // 两点不属于同一个SCC
                scc[u].emplace_back(v);
                in_deg[v]++;
            }
        }
    }

    // 计算缩点后入度为0的点的个数
    for(int i=1;i<=scnt;i++){
        if(in_deg[i]==0){
            ans++;
        }
    }

    printf("%d",ans);
    return 0;
}