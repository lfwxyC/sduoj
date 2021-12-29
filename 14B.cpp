#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e5 + 5;
const int inf = 1e9;
ll cnt[maxn], f[maxn][101];
int tot, head[maxn], to[maxn], cost[maxn], nxt[maxn];
ll n, m, k;

void init() {
    tot = 0;

    for (int i =0; i < maxn; i++) {
        head[i] = 0;
        cnt[i] = 0;

        f[i][0] = 0;
        for (int j = 1; j <= k; j++) {
            f[i][j] = inf;
        }
    }
}

void add_edge(int u, int v, int w) {
    tot++;
    to[tot] = v;
    cost[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int p) {
    bool isLeaf = 1;

    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i], w = cost[i];

        if (v != p) {
            isLeaf = 0;
            dfs(v, u);
            cnt[u] += cnt[v];

            for (int j = min(k, cnt[u]); j >= 0; j--) {
                for (int l = 0; l <= j && l <= min(k, cnt[v]); l++) {
                    f[u][j] = min(f[u][j], f[v][l] + f[u][j - l] + 1ll * l * (k - l) * w);
                }
            }
        }
    }

    if (isLeaf) {
        for (int i = 1; i <= k; i++) {
            f[u][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    init();
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        cnt[x] = 1;
        f[x][1] = 0;
    }

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        add_edge(a, b, c);
        add_edge(b, a, c);
    }

    dfs(1, -1);
    printf("%lld", f[1][k]);
    return 0;
}