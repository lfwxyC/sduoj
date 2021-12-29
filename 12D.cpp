#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 105;
vector<int> group[maxn];

int main(){
    ios::sync_with_stdio(false);

    int n, v, group_size = 0;
    cin >> n >> v;

    int w[n + 1], c[n + 1], k[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> k[i];
        group_size = max(group_size, k[i]);
    }

    for (int i = 1; i <= n; i++) {
        group[k[i]].emplace_back(i);
    }

    ll dp[v + 1];
    for (int i = 0; i <= v; i++) {
        dp[i] = 0;
    }

    // 对于每一组，都有取或不取两种情况
    for (int i = 1; i <= group_size; i++) { // 循环每一组
        for (int j = v; j >= 0; j--){ // 循环背包容量
            for (int m = 0; m < group[i].size(); m++) { // 循环该组的每一个物品
                if (j >= w[group[i][m]]) {
                    dp[j] = max(dp[j], dp[j - w[group[i][m]]] + c[group[i][m]]);
                }
            }
        }
    }

    cout << dp[v];
    return 0;
}