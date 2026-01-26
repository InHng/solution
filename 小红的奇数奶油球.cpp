#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> size(n + 1, 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : g[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v, u);
            size[u] += size[v];
        }
    };

    dfs(1, -1);

    int ans = 0;
    stack<PII> st;
    st.emplace(1, -1);

    while (!st.empty()) {
        int u = st.top().ff, fa = st.top().ss;
        st.pop();
        bool flag = ((n - size[u]) % 2 != 0) || (n == size[u]);
        for (int v : g[u]) {
            if (v == fa) {
                continue;
            }
            if (size[v] % 2 == 0) {
                flag = false;
            }
            st.emplace(v, u);
        }

        ans += flag;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
