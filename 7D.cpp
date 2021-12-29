#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
const int maxn=1e6+10,inf=1e9;

int dis[maxn];
bool vis[maxn];

void dijkstra(int s,int n,vector<pa> G[]){
    priority_queue<pa,vector<pa>,greater<pa>> q; // 按照权值排序的最小堆

    for(int i=1;i<=n;i++){
        dis[i]=inf;
        vis[i]=false;
    }

    dis[s]=0;
    q.push(make_pair(0,s));

    while(!q.empty()){
        int u=q.top().second;
        q.pop();

        if(vis[u]){
            continue;
        }
        vis[u]=true;

        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].second,w=G[u][i].first;

            // 松弛操作
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        int n,m,ans=0;
        scanf("%d%d",&n,&m);

        vector<pa> G1[n+1],G2[n+1];

        for(int j=0;j<m;j++){
            int s,e,c;
            scanf("%d%d%d",&s,&e,&c);

            G1[s].emplace_back(make_pair(c,e)); // 原图
            G2[e].emplace_back(make_pair(c,s)); // 反图
        }

        // 在原图对1做dijkstra,即可求得去的最短路径
        dijkstra(1,n,G1);
        for(int j=2;j<=n;j++){
            ans+=dis[j];
        }

        // 在反图对1做dijkstra,即可求得回来的最短路径
        dijkstra(1,n,G2);
        for(int j=2;j<=n;j++){
            ans+=dis[j];
        }

        printf("%d\n",ans);
    }

    return 0;
}