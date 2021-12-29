#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 2e5 + 5; // 无向图的边数是点数的两倍
int tot, head[maxn], to[maxn], nxt[maxn];
ll ans, cnt, deep[maxn], dp[maxn];

void init() {
    tot = 0;

    for (int i = 0; i < maxn; i++) {
        head[i] = 0;
        deep[i] = 0;
        dp[i] = 1;
    }
}

void add_edge(int u, int v) {
    tot++;
    to[tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int x, int p) {
    bool isLeaf = 1;

    for (int i = head[x]; i; i = nxt[i]) {
        int y = to[i];

        if (y != p) {
            isLeaf = 0;
            dfs(y, x);

            // deep[x]: 以x为根的子树的高度
            if (ans < deep[x] + deep[y] + 1) {
                ans = deep[x] + deep[y] + 1;
                cnt = dp[x] * dp[y];
            }
            else if (ans == deep[x] + deep[y] + 1) {
                cnt += dp[x] * dp[y];
            }

            if (deep[x] < deep[y] + 1) {
                deep[x] = deep[y] + 1;
                dp[x] = dp[y];
            }
            else if (deep[x] == deep[y] + 1) {
                dp[x] += dp[y];
            }
        }
    }

    if (isLeaf) {
        deep[x] = 0;
        dp[x] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        add_edge(u, v);
        add_edge(v, u);
    }

    ans = cnt = 0;
    dfs(1, -1);
    printf("%lld %lld", ans, cnt);
    return 0;
}