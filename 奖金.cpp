#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<int> final;
    vector<int> cnt(n + 1), dist(n + 1);
    while (m--) {
        cin >> a >> b;
        g[b].emplace_back(a);
        cnt[a]++;
    }

    function<bool()> topsort = [&]() -> bool {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!cnt[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int u = q.front();
            final.emplace_back(u);
            q.pop();
            for (int v : g[u]) {
                dist[v] = max(dist[v], dist[u] + 1);
                if (--cnt[v] == 0) {
                    q.push({v});
                }
            }
        }
        return final.size() == n;
    };

    if (topsort()) {
        cout << accumulate(dist.begin() + 1, dist.end(), 0) + 100 * dist.size() - 100;
    } else {
        cout << "Poor Xed";
    }
    return 0;
}
