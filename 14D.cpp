#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 5005;
const int p = 1e9 + 7;
ll cnt[maxn], sum[maxn];

int main() {
    ios::sync_with_stdio(false);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
        sum[i] = 0;
    }
    cnt[a] = 1;

    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            int limit = abs(j - b);
            int l = max(1, j - limit + 1), r = min(n, j + limit - 1);

            sum[l] += cnt[j];
            sum[l] %= p;

            sum[j] = (sum[j] - cnt[j] + p) % p;

            sum[j + 1] += cnt[j];
            sum[j + 1] %= p;

            sum[r + 1] = (sum[r + 1] - cnt[j] + p) % p;
        }

        for (int j = 1; j <= n; j++) {
            sum[j] += sum[j - 1];
            sum[j] %= p;
            cnt[j] = sum[j];
        }

        for (int j = 1; j <= n; j++) {
            sum[j] = 0;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i];
        ans %= p;
    }

    printf("%lld", ans);
    return 0;
}