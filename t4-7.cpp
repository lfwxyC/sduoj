#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e6+10;
const int inf = 1e9;
int n,x;
int a[maxn];
int l[maxn],r[maxn]; // 和a[i]矛盾的数的区间
int pre_l[maxn],pre_r[maxn]; // 和a[1]到a[i]矛盾的数的区间的并
int suf_l[maxn],suf_r[maxn]; // 和a[x]到a[i]矛盾的数的区间的并

void init(){
    for(int i = 0;i <= x + 1; i++){
        l[i] = pre_l[i] = suf_l[i] = inf; // 数组不初始化默认为0
    }

    set<int> s1;

    for(int i = 1;i <= n; i++){
        int t = a[i];
        auto it = s1.upper_bound(t); // 大于t的第一个位置

        if(it != s1.end()){
            l[t] = min(l[t],*it);
            r[t] = max(r[t],*s1.rbegin());
        }
        s1.insert(t);
    }

    set<int,greater<int>> s2; // 从大到小排序

    for(int i = n;i >= 1; i--){
        int t = a[i];
        auto it = s2.upper_bound(t); // 小于t的第一个位置

        if(it != s2.end()){
            l[t] = min(l[t],*s2.rbegin());
            r[t] = max(r[t],*it);
        }
        s2.insert(t);
    }

    for(int i = 1;i <= x; i++){
        pre_l[i] = min(pre_l[i-1],l[i]);
        pre_r[i] = max(pre_r[i-1],r[i]);
    }

    for(int i = x;i >= 1; i--){
        suf_l[i] = min(suf_l[i+1],l[i]);
        suf_r[i] = max(suf_r[i+1],r[i]);
    }
}

bool check(int left,int right){
    if(left >= pre_l[left]){
        return false;
    }

    if(right <= pre_r[left]){
        return false;
    }

    if(right <= suf_r[right]){
        return false;
    }

    if(left >= suf_l[right]){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);

    cin>>n>>x;

    for(int i = 1;i <= n; i++){
        cin>>a[i];
    }

    init();

    ll ans = 0;
    for(int i = 1;i <= x; i++){
        int lo = i,hi = x + 1;

        while(lo < hi){
            int mid = (lo + hi) / 2;

            if(check(i - 1,mid + 1)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        ans += x - lo + 1;
    }

    printf("%lld",ans);
    return 0;
}