#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int n, m, x, y, z;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 5];
    while (m--) { // 建图
        cin >> x >> y >> z;
        g[x].emplace_back(z, y);
    }

    function<int()> dijkstra = [&]() -> int {
        vector<int> dis(n + 5, INF); // 点 i 到点 1 的距离
        vector<bool> memo(n + 5, false); // 记录有没有到过点 i
        dis[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        while (q.size()) {
            int dist = q.top().ff, u = q.top().ss;
            q.pop();
            if (memo[u]) { // 已经到过这个点，不需要计算了
                continue;
            }
            memo[u] = true;
            for (pair<int, int> edge : g[u]) {
                int v = edge.ss, l = edge.ff;
                if (dis[v] > dis[u] + l) { // 如果可以有更小的距离
                    dis[v] = dis[u] + l;
                    q.push({dis[v], v});
                }
            }
        }
        return (dis[n] >= INF ? -1 : dis[n]);
    };

    cout << dijkstra() << endl;
    return 0;
}
