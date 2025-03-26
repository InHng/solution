#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

signed main() {
    cout << fixed << setprecision(2);
    int n, m, s, t;
    cin >> n;
    vector<pair<int, int>> idx(n + 1);
    vector<pair<double, int>> g[n + 1];
    vector<double> dist(n + 1, 0x3f3f3f3f);
    for (int i = 1; i <= n; ++i) {
        cin >> idx[i].ff >> idx[i].ss;
    }

    function<double(int, int)> f = [&](int i, int j) -> double {
        return sqrt(pow(idx[i].ff - idx[j].ff, 2) + pow(idx[i].ss - idx[j].ss, 2));
    };

    cin >> m;
    while (m--) {
        int i, j;
        cin >> i >> j;
        g[i].emplace_back(f(i, j), j);
        g[j].emplace_back(f(i, j), i);
    }
    cin >> s >> t;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.emplace(0, s);
    dist[s] = 0;
    while (q.size()) {
        auto [dis, u] = q.top();
        q.pop();
        if (u == t) {
            cout << dis << endl;
            return 0;
        }
        for (auto [d, v] : g[u]) {
            if (dist[v] > dis + d) {
                dist[v] = dis + d;
                q.emplace(dist[v], v);
            }
        }
    }
    return 0;
}
