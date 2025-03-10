#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n), g[n + 1], in(n + 1);
    while (k--) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i > 1) {
                g[a[i - 1]].emplace_back(a[i]);
                in[a[i]]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        sum++;
        for (int v : g[u]) {
            if (--in[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << (sum == n ? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
