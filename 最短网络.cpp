#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

struct DSU { // 并查集
    vector<int> pre, siz;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n);
        std::iota(pre.begin(), pre.end(), 0);
        siz.assign(n, 1);
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
        siz[x] += siz[y];
        pre[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

signed main() {
    int n, ans = 0;
    cin >> n;
    DSU dsu(n + 1);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int w;
            cin >> w;
            if (w) {
                edges.push_back({w, {i, j}});
            }
        }
    }
    sort(edges.begin(), edges.end());

    for (pair<int, pair<int, int>> edge : edges) {
        int w = edge.ff, x = edge.ss.ff, y = edge.ss.ss;
        if (dsu.merge(x, y)) {
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}
