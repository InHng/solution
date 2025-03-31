#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU { // 并查集
    vector<int> pre, siz;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n + 1);
        iota(pre.begin(), pre.end(), 0);
        siz.assign(n + 1, 1);
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
        } else if (siz[x] < siz[y]) {
            swap(x, y);
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
    int n, m, l, r, ans = 0;
    cin >> n >> m >> l >> r;
    DSU dsu1(n), dsu2(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w <= r) {
            dsu1.merge(u, v);
            if (w < l) {
                dsu2.merge(u, v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == dsu1.find(i)) {
            ans += dsu1.size(i) * (dsu1.size(i) - 1) / 2;
        }
        if (i == dsu2.find(i)) {
            ans -= dsu2.size(i) * (dsu2.size(i) - 1) / 2;
        }
    }
    cout << ans << endl;
}
