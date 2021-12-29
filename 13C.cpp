#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.length();
    int f[n + 1][n + 1];

    // 长度为1一定回文
    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = max(f[l][r - 1], f[l + 1][r]);

            if (s[l - 1] == s[r - 1]) {
                f[l][r] = f[l + 1][r - 1] + 2;
            }
        }
    }

    printf("%d",f[1][n]);
    return 0;
}