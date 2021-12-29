#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6 + 10;

ll ww[maxn], cc[maxn];

int main(){
    ios::sync_with_stdio(false);

    int n, v;
    cin >> n >> v;

    int w[n + 1], c[n + 1], k[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> k[i];
    }

    // 二进制拆分，从低位开始拆分
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = k[i];

        for (int j = 1; j <= t; j <<= 1) {
            cnt++;
            t -= j;

            ww[cnt] = w[i] * j;
            cc[cnt] = c[i] * j;
        }

        if (t) {
            cnt++;
            ww[cnt] = w[i] * t;
            cc[cnt] = c[i] * t;
        }
    }

    ll f[v + 1];
    for (int i = 0; i <= v; i++) {
        f[i] = 0;
    }

    // 拆分完之后变成0/1背包问题
    for (int i = 1; i <= cnt; i++) {
        for (int j = v; j >= 0; j--) {
            if (j >= ww[i]) {
                f[j] = max(f[j], f[j - ww[i]] + cc[i]);
            }
        }
    }

    cout << f[v];
    return 0;
}