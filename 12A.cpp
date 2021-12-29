#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n,v;
    cin >> n >> v;

    int w[n + 1], c[n + 1], f[v + 1];
    for (int i = 1; i <= n; i ++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 0; i <= v; i ++) {
        f[i] = 0;
    }

    // f[i]: 前i件物品放入容量为j的背包，最大价值
    for (int i = 1; i <= n; i ++) 
        for (int j = v; j >= 0; j --) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j-w[i]] + c[i]); // 第i件物品不放或放取最大值
            }
        }
    
    cout << f[v];
    return 0;
}