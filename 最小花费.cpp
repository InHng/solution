#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    cout << fixed << setprecision(8);
    int n, m, A, B, u, v;
    cin >> n >> m;
    vector<pair<double, int>> g[n + 1];
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].emplace_back(z, y);
        g[y].emplace_back(z, x);
    }
    cin >> A >> B;

    function<double()> dijkstra = [&]() -> double {
        vector<double> ans(n + 1);
        priority_queue<pair<double, int>> q;
        q.emplace(100.0, A);
        ans[A] = 100;
        while (q.size()) {
            auto [W, u] = q.top();
            q.pop();
            for (auto [w, v] : g[u]) {
                if (ans[v] < ((100 - w) / 100) * W) {
                    ans[v] = ((100 - w) / 100) * W;
                    q.emplace(ans[v], v);
                }
            }
        }
        return 100.0 / ans[B] * 100;
    };
    
    cout << dijkstra() << endl;
    return 0;
}
