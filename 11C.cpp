#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int inf=-1e9;

int main(){
    int n;
    scanf("%d",&n);

    int a[3][n];
    ll dp[n][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=inf;
        }
    }

    // dp[i][0/1/2]: 第i列选第0/1/2行的最小值
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            // 上一列选0/1/2行加上这一列与上一列的差的绝对值，取最小值
            dp[i][j]=min(dp[i-1][0]+abs(a[j][i]-a[0][i-1]),dp[i-1][1]+abs(a[j][i]-a[1][i-1]));
            dp[i][j]=min(dp[i][j],dp[i-1][2]+abs(a[j][i]-a[2][i-1]));
        }
    }

    ll ans=min(dp[n-1][0],dp[n-1][1]);
    ans=min(ans,dp[n-1][2]);

    printf("%lld",ans);
    return 0;
}