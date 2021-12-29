#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

int main(){
    int F;
    scanf("%d",&F);

    for(int i=0;i<F;i++){
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);

        // 初始化
        int dis[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=inf;
            }
        }

        for(int j=0;j<m;j++){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);

            // 两点之间的路径取最小值
            dis[s][e]=min(dis[s][e],t);
            dis[e][s]=min(dis[e][s],t);
        }

        for(int j=0;j<w;j++){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);

            dis[s][e]=min(dis[s][e],-t);
        }

        // Floyd
        bool flag=true;
        for(int k=1;k<=n&&flag;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }

                // 存在能回到过去的点
                if(dis[i][i]<0){
                    printf("YES\n");
                    flag=false;
                    break;
                }
            }
        }

        if(flag){
            printf("NO\n");
        }
    }

    return 0;
}