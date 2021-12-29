#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.length();
    int f[n][n];

    // 长度为1的串答案一定是1，长度为0的串答案一定为0
    for (int i = 0; i < n; i++) {
        f[i][i] = 1;

        if (i) {
            f[i][i - 1] = 0;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = inf;

            if ((s[l] == '[' && s[r] == ']') || (s[l] == '(' && s[r] == ')')){
                f[l][r] = f[l + 1][r - 1];
            }
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
            }
        }
    }

    printf("%d",f[0][n - 1]);
    return 0;
}