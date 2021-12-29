#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
const int inf=1e9;

int n;
int dis[maxn],cnt[maxn];
bool can[maxn];
vector<pair<int,int>> G[maxn];

bool spfa(int s){
    for(int i=0;i<=n;i++){
        can[i]=false;
        dis[i]=inf;
        cnt[i]=0;
    }

    dis[s]=0;
    can[s]=true;

    queue<int> q;
    q.emplace(s);

    while (!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].first,w=G[u][i].second;

            if(dis[v]>dis[u]+w){ // 松弛操作
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;

                if(cnt[v]>=n){ // 存在负环
                    return false;
                }

                if(!can[v]){
                    can[v]=true;
                    q.emplace(v);
                }
            }
        }
        can[u]=false;
    }
    return true;
}

int main(){
    int m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){
        int k,a,b,c;
        scanf("%d%d%d%d",&k,&a,&b,&c);

        switch (k)
        {
        case 1: // 最多种c瓶，dis[b] - dis[a - 1] <= c
            G[a-1].emplace_back(make_pair(b,c));
            break;
        case 2: // 最少种c瓶，dis[b] - dis[a - 1] >= c
            G[b].emplace_back(make_pair(a-1,-c));
            break;
        case 3: // 少于c瓶，dis[b] - dis[a - 1] < c
            G[a-1].emplace_back(make_pair(b,c-1));
            break;
        case 4: // 多于c瓶，dis[b] - dis[a - 1] > c
            G[b].emplace_back(make_pair(a-1,-c-1));
            break;
        case 5: // 等于c瓶，c <= dis[b] - dis[a - 1] <= c
            G[a-1].emplace_back(make_pair(b,c));
            G[b].emplace_back(make_pair(a-1,-c));
            break;
        default:
            break;
        }
    }

    // 每个坑最少种0瓶，最多种1瓶，0 <= dis[i + 1] - dis[i] <= 1
    for(int i=0;i<n;i++){
        G[i].emplace_back(make_pair(i+1,1));
        G[i+1].emplace_back(make_pair(i,0));
    }

    // 将差分约束转换为求单源最短路径
    if(!spfa(0)){
        printf("impossible ");
    }else{
        printf("%d",dis[n]);
    }

    return 0;
}