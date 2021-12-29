#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2010][2010], d[2010][2010], s[2010][2010];

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        a[i][0] = 0;

        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j] - a[i][j - 1];
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int lx, ly, rx, ry, c;
        cin >> lx >> ly >> rx >> ry >> c;

        for (int j = lx; j <= rx; j++) {
            d[j][ly] += c;
            d[j][ry + 1] -= c;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = a[i][j - 1] + d[i][j];
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}