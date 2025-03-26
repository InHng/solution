#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
const int INF = 0x3f3f3f3f;

signed main() {
    int n, m, b;
    cin >> n >> m >> b;
    vector<pair<int, int>> g[n + 1];
    vector<int> dist(n + 1, INF);
    while (m--) {
        int r, s, l;
        cin >> r >> s >> l;
        g[r].emplace_back(l, s);
        g[s].emplace_back(l, r);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.emplace(1);
    dist[1] = 0;
    while (q.size()) {
        int u = q.top();
        q.pop();
        for (auto [dis, v]: g[u]) {
            if (dist[v] > dist[u] + dis) {
                dist[v] = dist[u] + dis;
                q.emplace(v);
            }
        }
    }
    while (b--) {
        int p, q;
        cin >> p >> q;
        cout << dist[p] + dist[q] << endl;
    }
    return 0;
}
