#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1e6+10;
int n;
ll s[maxn];

int lb(int x){
    return x&(-x);
}

ll ask(int x){ // 查询d[1]至d[x]的和
    ll res=0;

    for(int i=x;i>=1;i-=lb(i)){
        res+=s[i];
    }
    return res;
}

void upd(int x,int v){ // 将d[x]的值修改为v
    for(int i=x;i<=n;i+=lb(i)){ // 修改所有包含d[x]的s[i]的值
        s[i]+=v;
    }
}

int main(){
    ios::sync_with_stdio(false);

    int q;
    cin>>n>>q;

    int d[n+1];
    for(int i=1;i<=n;i++){
        cin>>d[i];
        s[i]=0;
    }

    for(int i=1;i<=n;i++){
        upd(i,d[i]);
    }

    for(int i=0;i<q;i++){
        int opt;
        cin>>opt;

        switch(opt){
            case 1:{
                int i,x;
                cin>>i>>x;

                upd(i,x);
                break;
            }
            case 2:{
                int l,r;
                cin>>l>>r;

                ll ans=ask(r)-ask(l-1); // 查询d[l,r]的值
                cout<<ans<<endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}