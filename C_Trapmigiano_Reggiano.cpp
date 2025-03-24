#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    stack<int> s;
    queue<pair<int, int>> q;
    q.emplace(en, -1);
    s.emplace(en);
    while (q.size()) {
        auto [u, father] = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == father) {
                continue;
            }
            q.emplace(v, u);
            s.emplace(v);
        }
    }
    while (s.size()) {
        int x = s.top();
        s.pop();
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    int T; cin >> T; while (T--)
    solve();
}
