#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
int s[maxn],f[maxn];

int lb(int x){
    return x&(-x);
}

int ask(int x) {
    int res = 0;
    for (int i = x; i >= 1; i -= lb(i)) 
        res = max(res, s[i]);
    return res;
}

void upd(int x,int v) {
    for (int i = x; i < maxn; i += lb(i)) 
        s[i] = max(s[i], v);
}

int main(){
    int n;
    scanf("%d",&n);

    int d[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }

    for(int i=1;i<maxn;i++){
        s[i]=0;
    }

    for(int i=1;i<=n;i++){
        // f[i]: 以d[i]结尾的最长上升子序列
        // f[i] = max(f[j]) + 1 (j < i && d[j] < d[i])
        f[i]=ask(d[i] - 1) + 1; 
        upd(d[i], f[i]);
    }

    sort(f+1,f+n+1);
    printf("%d",f[n]);

    return 0;
}