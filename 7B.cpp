#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
int w[maxn],m[maxn],a[maxn],b[maxn];

int main(){
    int n;
    scanf("%d",&n);

    // 初始化差分数组
    for(int i=1;i<maxn;i++){
        a[i]=0;
        b[i]=0;
    }

    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);

        a[l]+=1;
        a[r]-=1;
    }

    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);

        b[l]+=1;
        b[r]-=1;
    }

    int ans=0;
    w[0]=m[0]=0;

    for(int i=1;i<maxn;i++){
        // 前缀和求原数组
        w[i]=w[i-1]+a[i];
        m[i]=m[i-1]+b[i];

        if(w[i]==1&&m[i]==1){
            ans++;
        }
    }

    printf("%d",ans);
    return 0;
}