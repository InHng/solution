#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 1e9 + 7;

int ksm(int a, int b, int mod) {
    a %= mod;
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n, total_exp = 0;
    cin >> n;
    vector<int> g[n + 1], in(n + 1), p(n + 1), vis(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    p[1] = vis[1] = 1;
    queue<int> q;
    q.emplace(1);
    while (q.size()) {
        int u = q.front(), nowp = p[q.front()];
        q.pop();
        total_exp = (total_exp + nowp) % mod;
        int inv_in = ksm(in[u], mod - 2, mod);
        int nextp = nowp * inv_in % mod;
        for (int v : g[u]) {
            if (not vis[v]) {
                vis[v] = 1;
                p[v] = nextp;
                q.emplace(v);
            }
        }
    }
    cout << total_exp << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
