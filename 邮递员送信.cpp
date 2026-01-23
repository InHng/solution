#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

signed main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> dis_go(n + 1, 0x3f3f3f3f), dis_back(n + 1, 0x3f3f3f3f);
    vector<pair<int, int>> go[n + 1], back[n + 1];
    dis_go[1] = 0, dis_back[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        go[u].emplace_back(v, w);
        back[v].emplace_back(u, w);
    }
    q.emplace(0, 1);
    while (q.size()) {
        int u = q.top().ss;
        q.pop();
        for (int i = 0; i < go[u].size(); ++i) {
            int v = go[u][i].ff, w = go[u][i].ss;
            if (dis_go[u] + w < dis_go[v]) {
                dis_go[v] = dis_go[u] + w;
                q.emplace(dis_go[v], v);
            }
        }
    }
    q.emplace(0, 1);
    while (q.size()) {
        int u = q.top().ss;
        q.pop();
        for (int i = 0; i < back[u].size(); ++i) {
            int v = back[u][i].ff, w = back[u][i].ss;
            if (dis_back[u] + w < dis_back[v]) {
                dis_back[v] = dis_back[u] + w;
                q.emplace(dis_back[v], v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += dis_go[i] + dis_back[i];
    }
    cout << ans << endl;
}
