#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, b, e;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + m + 1);
    map<int, int> mp;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        if (not mp.count(c)) { // 对每个颜色建一个虚拟点
            mp[c] = ++n;
        }
        // 每到一个新颜色就加一
        g[u].emplace_back(mp[c], 1);
        g[v].emplace_back(mp[c], 1);
        g[mp[c]].emplace_back(u, 0);
        g[mp[c]].emplace_back(v, 0);
    }
    cin >> b >> e;
    function<int()> dijkstra = [&]() -> int {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dis(n + 1, INF);
        vector<bool> memo(n + 1);
        dis[b] = 0;
        q.emplace(0, b);
        while (q.size()) {
            auto [dist, u] =  q.top();
            q.pop();
            if (u == e) {
                return dis[e];
            }
            if (memo[u]) {
                continue;
            }
            memo[u] = true;
            for (auto [v, w] : g[u]) {
                dis[v] = min(dis[v], dist + w);
                q.emplace(dist + w, v);
            }
        }
        return 0;
    };
    
    cout << dijkstra() << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
