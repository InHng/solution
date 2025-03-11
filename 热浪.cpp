#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int T, C, start, end;
    cin >> T >> C >> start >> end;
    vector<pair<int, int>> g[T + 1];
    while (C--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    function<int()> dijkstra = [&]() -> int {
        vector<int> dis(T + 1, INF);
        vector<bool> memo(T + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[start] = 0;
        q.emplace(0, start);
        while (q.size()) {
            auto [W, u] = q.top();
            q.pop();
            memo[u] = true;
            for (auto [v, w] : g[u]) {
                if (memo[v]) {
                    continue;
                }
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.emplace(dis[v], v);
                }
            }
        }
        return dis[end];
    };
    
    cout << dijkstra();
    return 0;
}
