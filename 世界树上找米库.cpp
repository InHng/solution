#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, mx = -1;
    cin >> n;
    vector<int> g[n + 1], miku;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    queue<int> q;
    vector<int> dist(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            q.emplace(i);
            dist[i] = 0;
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 1) {
            mx = max(mx, dist[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 1 and dist[i] == mx) {
            miku.emplace_back(i);
        }
    }
    cout << miku.size() << endl;
    for (int x : miku) {
        cout << x << " \n"[x == miku.back()];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
