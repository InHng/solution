#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

void solve() {
    int n, u, v, ans;
    cin >> n;
    ans = 0;
    vector<pair<int, int>> graph[n + 1];
    vector<int> dp(n + 1, 0), idx(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    function<void(int)> dfs = [&](int u) -> void {
        for (pair<int, int> v : graph[u]) {
            if (dp[v.ff] == 0) {
                dp[v.ff] = dp[u] + (v.ss <= idx[u]);
                idx[v.ff] = v.ss;
                dfs(v.ff);
            }
        }
    };

    dp[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

signed main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
