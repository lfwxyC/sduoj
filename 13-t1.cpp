#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);

    ll l, r, k;
    cin >> l >> r >> k;
    bool flag = true;

    for (int i = 0; i < 100; i++) {
        ll mul = pow(k, i);

        if (mul > r) break;

        if (mul >= l) {
            printf("%lld ", mul);
            flag = false;
        }
    }

    if (flag) {
        printf("-1");
    }
    return 0;
}