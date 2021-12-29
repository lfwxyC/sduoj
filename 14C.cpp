#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6 + 10;
const int inf = 1e9;
ll a[maxn], sum[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    deque<int> dq;
    ll ans = 0;
    dq.emplace_back(0);

    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && sum[dq.back()] > sum[i]) {
            dq.pop_back();
        }

        while (!dq.empty() && dq.front() < i - m) {
            dq.pop_front();
        }

        dq.emplace_back(i);
        // f[i] = sum[i] - min(sum[k]) (i - m <= k <= i)
        ans = max(ans, sum[i] - sum[dq.front()]);
    }

    printf("%lld", ans);
    return 0;
}