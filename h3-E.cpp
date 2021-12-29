#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N][N];
int cnt, n, k;
bool vis[N];

void dfs(int x, int row) {
    if (x == k) {
        cnt++;
        return;
    }

    if (x > k || row > n) return;

    for (int i = 1; i <= n; i++) {
        if (a[row][i] && !vis[i]) {
            vis[i] = 1;
            dfs(x + 1, row + 1);
            vis[i] = 0;
        }
    }
    dfs(x, row + 1);
}

int main() {
    while (1) {
        cin >> n >> k;

        if (n == -1 && k == -1) break;

        cnt = 0;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;

                if (c == '#') {
                    a[i][j] = 1;
                }
            }
        }

        dfs(0, 1);
        printf("%d\n", cnt);
    }

    return 0;
}