#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 15;
const int p = 1e9 + 7;
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
        int n, k;
        cin >> n >> k;

        Matrix ans, ini, dp;
        for (int i = 0; i < k + 2; i++) {
            ini.x[i][0] = 1;
        }

        dp.x[k + 1][k + 1] = 1;
        for (int i = k; i > 0; i--) {
            for (int j = 1; j < k + 2; j++) {
                dp.x[i][j] = dp.x[i + 1][j] + dp.x[i + 1][j + 1];
            }
        }

        for (int j = 1; j < k + 2; j++) {
            dp.x[0][j] = dp.x[1][j];
        }
        dp.x[0][0] = 1;

        dp = quick_pow(dp, n - 1);
        ans = dp * ini;

        printf("%d\n", ans.x[0][0]);
    }

    return 0;
}