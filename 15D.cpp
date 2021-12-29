#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105;

struct Matrix{
    ll x[N][N];

    Matrix() {
        memset(x, 0, sizeof x);
    }
    Matrix(const Matrix& m) {
        memcpy(x, m.x, sizeof x);
    }

    Matrix operator * (const Matrix& m) const {
        Matrix res;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    res.x[i][j] = max(res.x[i][j], x[i][k] + m.x[k][j]);
                }
            }
        }
        return res;
    }
};

Matrix quick_pow(Matrix a, int x) {
    Matrix res;
    res.x[0][0] = res.x[1][1] = 0;
    res.x[0][1] = res.x[1][0] = 0;

    while (x) {
        if (x & 1) {
            res = res * a;
        }

        a = a * a;
        x >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Matrix ans, ini, h;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h.x[j][i];
        }
    }

    // f[i][j]: 第i天穿衬衫j的快乐值
    // f[i][j] = max(f[i - 1][k] + h[k][j]) (1 <= k <= m)
    h = quick_pow(h, n - 1);
    ans = h * ini;

    ll res = 0;
    for (int i = 0; i < m; i++) {
        res = max(res, ans.x[i][0]);
    }

    printf("%lld", res);
    return 0;
}