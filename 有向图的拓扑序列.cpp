#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1], in(n + 1), ans;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v); // 建立单向边
        in[v]++; // 入度加一
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
            ans.emplace_back(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (--in[v] == 0) {
                q.emplace(v);
                ans.emplace_back(v);
            }
        }
    }
    if (ans.size() == n) {
        for (int ai : ans) {
            cout << ai << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}
