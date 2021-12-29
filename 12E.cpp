#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);

    ll n, v;
    cin >> n >> v;

    int size1 = n / 2, size2 = n - n / 2;
    int w1[size1 + 1], c1[size1 + 1], w2[size2 + 1], c2[size2 + 1];
    for (int i = 1; i <= size1; i++) {
            cin >> w1[i] >> c1[i];
    }

    for (int i = 1; i <= size2; i++) {
        cin >> w2[i] >> c2[i];
    }

    vector<pair<ll,ll>> group1, group2;
    ll num1 = pow(2, size1), num2 = pow(2, size2);
    // 对两组分别进行子集枚举
    for (ll i = 0; i < num1; i++) {
        ll tmp_w = 0, tmp_c = 0, k = i;

        for (int j = 1; j <= size1; j++) {
            int flag = k & 1;
            k >>= 1;

            tmp_w += w1[j] * flag;
            tmp_c += c1[j] * flag;
        }

        if (tmp_w <= v)
            group1.emplace_back(make_pair(tmp_w,tmp_c));
    }

    for (ll i = 0; i < num2; i++) {
        ll tmp_w = 0, tmp_c = 0, k = i;

        for (int j = 1; j <= size2; j++) {
            int flag = k & 1;
            k >>= 1;

            tmp_w += w2[j] * flag;
            tmp_c += c2[j] * flag;
        }
        
        if (tmp_w <= v)
            group2.emplace_back(make_pair(tmp_w,tmp_c));
    }

    // 按体积从小到大排序
    sort(group1.begin(),group1.end());
    sort(group2.begin(),group2.end());

    ll pre[group2.size()];
    pre[0] = 0;

    for (ll i = 1; i < group2.size(); i++) {
        pre[i] = max(pre[i - 1], group2[i].second);
    }

    ll ans = 0;
    // 遍历第一组，对于每个体积wi,在第二组中二分查找体积小于等于v-wi的最大价值
    for (auto& x:group1) {
        ll ww = x.first, cc = x.second;
        ll lo = 0, hi = group2.size() - 1;

        while (lo <= hi) {
            ll mid = lo + hi >> 1;

            if(ww + group2[mid].first <= v) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        ans = max(ans, cc + pre[hi]);
    }

    cout << ans;
    return 0;
}