#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n, v;
    cin >> n >> v;

    int w[n + 1], c[n + 1], f[v + 1];
    for (int i = 1; i <= n; i ++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 0; i <= v; i ++) {
        f[i] = 0;
    }

    for (int i = 1; i <= n; i ++) 
        for (int j = 0; j <= v; j ++) 
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + c[i]);
            }

    cout << f[v];
    return 0;
}