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
    int n, m, k, ans = 0, cnt = 0;
    cin >> n >> m >> k;
    DSU dsu(n);
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < m; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        a.emplace_back(l, x, y);
    }
    sort(a.begin(), a.end());
    for (auto [l, x, y] : a) {
        if (dsu.merge(x, y)) {
            ans += l;
            if (++cnt == n - k) {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << "No Answer" << endl;
}
