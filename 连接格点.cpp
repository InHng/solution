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
    int n, m, ans = 0;
    cin >> n >> m;
    DSU dsu(n * m + 1);
    int x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int u = (x1 - 1) * m + y1, v = (x2 - 1) * m + y2;
        dsu.merge(u, v);
    }
    
    // 由于竖向花费最小，所以先判断竖向
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < n; ++j) {
            int u = (j - 1) * m + i, v = j * m + i;
            if (dsu.merge(u, v)) {
                ans += 1;
            }
        }
    }
    // 横向合并
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            int u = (i - 1) * m + j, v = (i - 1) * m + j + 1;
            if (dsu.merge(u, v)) {
                ans += 2; 
            }
        }
    }
    cout << ans << endl;
    return 0;
}
