#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int n, p, c, ans = INF;
    cin >> n >> p >> c;
    vector<int> cows(n);
    vector<pair<int, int>> g[p + 1];
    for (int &cow : cows) {
        cin >> cow;
    }
    while (c--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }

    function<int(int)> dijkstra = [&](int u) -> int {
        vector<int> dis(p + 1, INF);
        vector<bool> memo(p + 1, false);
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, u);
        dis[u] = 0;
        while (q.size()) {
            auto [dist, u] = q.top();
            q.pop();
            memo[u] = true;
            for (auto [w, v] : g[u]) {
                if (memo[v]) {
                    continue;
                }
                if (dis[v] > dist + w) {
                    dis[v] = dist + w;
                    q.emplace(dis[v], v);
                }
            }
        }
        for (int cow : cows) {
            ans += dis[cow];
        }
        return ans;
    };

    for (int i = 1; i <= p; ++i) {
        ans = min(ans, dijkstra(i));
    }
    cout << ans << endl;
    return 0;
}
