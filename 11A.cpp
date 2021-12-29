#include<bits/stdc++.h>
using namespace std;

const int p=998244353;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int f[n+1],sf[n+1];
    for(int i=1;i<=n;i++){
        f[i]=-1;
    }

    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);

        f[x]=0;
    }

    f[0]=sf[0]=1;
    for(int i=1;i<=n;i++){
        if(f[i]==0){ // 不安全的台阶
            sf[i]=(sf[i-1]+f[i])%p;
            continue;
        }

        // f[i] = sum(f[j]) (i - k <= j < i, j安全)
        if(i-k-1>=0){
            f[i]=(sf[i-1]-sf[i-k-1]+p)%p;
        }else{
            f[i]=sf[i-1];
        }
        
        sf[i]=(sf[i-1]+f[i])%p;
    }

    int ans=f[n]%p;
    printf("%d",ans);
    return 0;
}