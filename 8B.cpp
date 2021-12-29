#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
int n;
int in_deg[maxn];
vector<int> G[maxn];

void toposort(){ // 拓扑排序
    priority_queue<int,vector<int>,greater<int>> q;

    // 把入度为0的点放入小根堆
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            q.emplace(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int u=q.top();
        q.pop();

        ans.emplace_back(u);

        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            in_deg[v]--;

            if(in_deg[v]==0){
                q.emplace(v);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        in_deg[i]=0;
    }

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);

        G[u].emplace_back(v);
        in_deg[v]++; // 计算入度
    }

    toposort();
    return 0;
}