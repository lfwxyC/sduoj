#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1e6+10;
int cnt[maxn];

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<maxn;i++){
        cnt[i]=0;
    }

    int max_x=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);

        cnt[x]++;
        max_x=max(max_x,x);
    }

    ll dp[max_x+1];
    dp[0]=0;
    dp[1]=cnt[1];

    // dp[i]:大小为1 ~ i的数，能拿到的最大分数
    for(int i=2;i<=max_x;i++){
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i); // 拿1 ~ （i - 1）的数，或者拿1 ~ （i - 2） + i的数
    }

    printf("%lld",dp[max_x]);
    return 0;
}