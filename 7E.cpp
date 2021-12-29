#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
const int maxn=1e5+5,inf=1e9;

int dis[maxn];
bool vis[maxn];

struct Edge
{
    int v,w,t;
}typedef Edge;

vector<Edge> G[maxn];

void dijkstra(int s,int n,int mid){
    priority_queue<pa,vector<pa>,greater<pa>> q;

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
            int v=G[u][i].v,w=G[u][i].w,t=G[u][i].t;
            
            // 只能选权值大于mid的边
            if(w<mid){
                continue;
            }

            if(dis[v]>dis[u]+t){
                dis[v]=dis[u]+t;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}

int main(){
    int X;
    scanf("%d",&X);

    for(int i=0;i<X;i++){
        int n,m,t;
        scanf("%d%d%d",&n,&m,&t);

        int maxc=0,minc=inf;

        // 初始化图
        for(int i=0;i<maxn;i++){
            G[i].clear();
        }

        for(int j=0;j<m;j++){
            int a,b,c,d;
            Edge e1,e2;
            scanf("%d%d%d%d",&a,&b,&c,&d);

            // 无向图
            e1.v=b,e1.w=c,e1.t=d;
            e2.v=a,e2.w=c,e2.t=d;
            G[a].emplace_back(e1);
            G[b].emplace_back(e2);

            maxc=max(maxc,c);
            minc=min(minc,c);
        }

        // 二分答案，mid为能选的最小权值
        int lo=minc,hi=maxc;
        while (lo<=hi)
        {
            int mid=(lo+hi)/2;
            dijkstra(1,n,mid);

            if(dis[n]>t){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        
        printf("%d\n",hi);
    }

    return 0;
}