#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll f[20][1 << 20];

int main() {
    ios::sync_with_stdio(false);
    int h, w, n;
    

    cin >> h >> w;
    n = 1 << w;

    for (int i = 0; i < n; i++) {
        f[0][i] = 0;
    }
    f[0][0] = 1; // 第0行不能对第1行有影响，故状态必须为0，仅有这一种方案可行

    // f[i][S]: 填充到第i行，状态为S的方案数
    for (int i = 1; i <= h; i++) {
        for (int S1 = 0; S1 < n; S1++) {
            f[i][S1] = 0;

            for (int S2 = 0; S2 < n; S2++) {
                if (S1 & S2) continue; // 每个1下方必须是0，因为竖着的长方形需要补全

                // 每一段连续的0必须为偶数个，因为当出现0时说明上下两行均为横着的长方形
                int S3 = S1 | S2, flag = 0;
                for (int j = 0; j < w; j++) {
                    if ((S3 & 1) && flag) break;

                    if ((S3 & 1) == 0) {
                        flag ^= 1;
                    }

                    S3 >>= 1;
                }
                if (flag) continue;

                f[i][S1] += f[i - 1][S2];
            }
        }
    }

    printf("%lld", f[h][0]);
    return 0;
}