#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        g[i].emplace_back(k, j);
        g[j].emplace_back(k, i);
    }

    function<int()> dijkstra = [&]() -> int {
        vector<int> dis(n + 1, INF);
        vector<bool> memo(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        q.emplace(0, 1);
        dis[1] = 0;
        while (q.size()) {
            auto [days, u] = q.top();
            q.pop();
            memo[u] = true;
            for (auto [w, v] : g[u]) {
                if (memo[v]) {
                    continue;
                }
                if (dis[v] > days + w) {
                    dis[v] = days + w;
                    q.emplace(dis[v], v);
                }
            }
        }
        return *max_element(dis.begin() + 1, dis.end());
    };

    cout << (dijkstra() >= INF ? -1 : dijkstra());
    return 0;
}
