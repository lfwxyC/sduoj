#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3;
const int p = 998244353;
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
                    res.x[i][j] += x[i][k] * m.x[k][j] % p;
                    res.x[i][j] %= p;
                }
            }
        }
        return res;
    }
};

Matrix quick_pow(Matrix a, int x) {
    Matrix res;
    res.x[0][0] = res.x[1][1] = 1;
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Matrix ans, ini, dp;
        ini.x[0][0] = 1, ini.x[1][0] = 0, ini.x[2][0] = 2;
        dp.x[0][0] = dp.x[0][2] = 1, dp.x[0][1] = 0;
        dp.x[1][0] = 0, dp.x[1][1] = dp.x[1][2] = 1;
        dp.x[2][0] = dp.x[2][1] = 2, dp.x[2][2] = 1;

        dp = quick_pow(dp, n - 1);
        ans = dp * ini;

        printf("%d\n", ans.x[0][0]);
    }

    return 0;
}