#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int m, n, ans = INF;
    cin >> m >> n;
    vector<pair<int, int>> g[n + 1];
    vector<int> price(n + 1), level(n + 1);
    for (int i = 1; i <= n; ++i) {
        int X;
        cin >> price[i] >> level[i] >> X;
        while (X--) {
            int id, value;
            cin >> id >> value;
            g[i].emplace_back(id, value);
        }
    }

    function<int(int, int)> dijkstra = [&](int down, int up) -> int {
        // dist[i] 表示从 酋长 到达 i 点所需要的价格
        vector<int> dist(n + 1, INF), memo(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 1); // 所要花费，当前节点
        dist[1] = 0;
        while (q.size()) {
            int u = q.top().ss;
            q.pop();
            if (memo[u]) {
                continue;
            }
            memo[u] = 1;
            for (auto [v, value] : g[u]) {
                // 需要限定范围
                if (dist[v] > dist[u] + value and level[v] >= down and level[v] <= up) {
                    dist[v] = dist[u] + value;
                    q.emplace(dist[v], v);
                }
            }
        }

        int ans = INF;
        for (int i = 1; i <= n; ++i) { // 寻找最小结果
            ans = min(ans, dist[i] + price[i]);
        }
        return ans;
    };

    for (int i = level[1] - m; i <= level[1]; ++i) { // 等级范围必须包括酋长的所在等级
        ans = min(ans, dijkstra(i, i + m));
    }
    cout << ans << endl;
    return 0;
}
