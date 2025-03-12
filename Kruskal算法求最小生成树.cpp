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
        iota(pre.begin(), pre.end(), 0);
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
    int n, m, ans = 0, cnt = 0;
    cin >> n >> m;
    DSU dsu(n + 1);
    vector<pair<int, pair<int, int>>> edges(m);
    for (pair<int, pair<int, int>> &edge : edges) {
        cin >> edge.ss.ff >> edge.ss.ss >> edge.ff;
    }
    sort(edges.begin(), edges.end());
    for (pair<int, pair<int, int>> edge : edges) {
        int w = edge.ff, u = edge.ss.ff, v = edge.ss.ss;
        if (dsu.merge(u, v)) {
            ans += w;
            ++cnt;
        }
    }
    if (cnt == n - 1) {
        cout << ans << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}
