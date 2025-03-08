#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n + 1), g[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    function<void(int, int, int)> dfs = [&](int u, int father, int cnt) {
        if (u ^ 1 and g[u].size() == 1) {
            ++ans;
            return;
        }
        for (int v : g[u]) {
            if (v == father or cnt + a[v] > m) {
                continue;
            }
            if (a[v]) {
                dfs(v, u, cnt + 1);
            } else {
                dfs(v, u, 0);
            }
        }
    };

    dfs(1, -1, a[1]);
    cout << ans << endl;
    return 0;
}
