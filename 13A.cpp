#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[2 * n], f1[2 * n][2 * n], f2[2 * n][2 * n], sum[2 * n][2 * n];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f1[i][i] = 0;
        f2[i][i] = 0;
        sum[i][i] = a[i];
    }

    // 拆环为链
    for (int i = n + 1; i < 2 * n; i++) {
        a[i] = a[i - n];
        f1[i][i] = 0;
        f2[i][i] = 0;
        sum[i][i] = a[i];
    }

    // f1[i][j]: 区间i, j的最小值；f2[i][j]: 区间i, j的最大值
    // f[i][j] = sum[i][j] + min/max(f[i][k] + f[k + 1][j]) (i <= k < j)
    for (int len = 2; len <= 2 * n; len++) {
        for (int i = 1; i <= 2 * n - len + 1; i++) {
            int l = i, r = i + len - 1, tmp1 = inf, tmp2 = 0;

            for (int k = l; k < r; k++) {
                tmp1 = min(tmp1, f1[l][k] + f1[k + 1][r]);
                tmp2 = max(tmp2, f2[l][k] + f2[k + 1][r]);
            }

            sum[l][r] = sum[l][r - 1] + a[r];
            f1[l][r] = sum[l][r] + tmp1;
            f2[l][r] = sum[l][r] + tmp2;
        }
    }

    int ans1 = inf, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 = min(ans1, f1[i][i + n - 1]);
        ans2 = max(ans2, f2[i][i + n - 1]);
    }

    printf("%d\n%d",ans1,ans2);
    return 0;
}