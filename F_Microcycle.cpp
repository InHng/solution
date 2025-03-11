#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU { // 并查集
    vector<int> pre;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n);
        std::iota(pre.begin(), pre.end(), 0);
    }
    
    int find(int x) {
        if (pre[x] == x) {
            return x;
        }
        return pre[x] = find(pre[x]);
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        pre[y] = x;
        return true;
    }
};

void solve() {
    int n, m, ans, start, end;
    cin >> n >> m;
    DSU dsu(n + 1);
    vector<int> ans_path;
    vector<int> g[n + 1];
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end(), greater()); // 由大到小排序以便找到最小权重
    for (auto [w, u, v] : edges) {
        if (not dsu.merge(u, v)) { // 如果这条边的两个点已经连接，说明这个边连成后即可成圈
            ans = w;
            start = u;
            end = v;
        } else {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }

    function<bool(int, int)> dfs = [&](int u, int father) -> bool {
        if (u == end) { // 说明这条 dfs 最终可以找到这个环
            ans_path.emplace_back(u);
            return true;
        }
        for (int v : g[u]) {
            if (v == father) {
                continue;
            }
            if (dfs(v, u)) { // 如果往下 dfs 可以找到这个环
                ans_path.emplace_back(u);
                return true;
            }
        }
        return false;
    };
    dfs(start, -1);
    cout << ans << " " << ans_path.size() << endl;
    for (int x : ans_path) {
        cout << x << " \n"[x == ans_path.back()];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
