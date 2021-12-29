#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Tr{
    int id, opt;
    ll t;
    vector<int> depend;
}typedef Tr;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    ll server_time[n + 1];
    int server_in_deg[n + 1];
    vector<Tr> topo[n + 1];
    vector<int> server[n + 1];

    for (int i = 1; i <= n; i++) { // 服务器
        int k;
        cin >> k;

        server_in_deg[i] = 0, server_time[i] = 0;

        vector<int> G[k + 1];
        vector<Tr> tmp;
        int tr_in_deg[k + 1];

        for (int j = 1; j <= k; j++) { // 任务
            Tr tr;
            int l;
            cin >> l;

            tr.id = j, tr_in_deg[j] = l;
            for (int x = 0; x < l; x++) { // 依赖的任务
                int u;
                cin >> u;

                tr.depend.emplace_back(u);
                G[u].emplace_back(j);
            }

            cin >> tr.opt >> tr.t;
            if (tr.opt == 1) {
                server[tr.t].emplace_back(i);
                server_in_deg[i]++;
            }

            tmp.emplace_back(tr);
        }

        queue<int> q;
        for (int j = 1; j <= k; j++) {
            if (tr_in_deg[j] == 0) {
                q.emplace(j);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo[i].emplace_back(tmp[u - 1]);

            for (auto& v:G[u]) {
                tr_in_deg[v]--;

                if (tr_in_deg[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (server_in_deg[i] == 0) {
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int k = topo[u].size();
        ll time[k + 1];

        for (auto& tr:topo[u]) {
            if (tr.opt == 0) {
                time[tr.id] = tr.t;
            }
            else {
                time[tr.id] = server_time[tr.t] + 1;
            }

            ll tmp = 0;
            for (auto& d:tr.depend) {
                tmp = max(time[d], tmp);
            }

            time[tr.id] += tmp;
            server_time[u] = max(server_time[u], time[tr.id]);
        }

        for (auto& x:server[u]) {
            server_in_deg[x]--;

            if (server_in_deg[x] == 0) {
                q.emplace(x);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;

        printf("%lld\n", server_time[id]);
    }

    return 0;
}