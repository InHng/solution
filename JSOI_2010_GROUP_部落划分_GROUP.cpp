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
    int n, k, cnt = 0;
    cin >> n >> k;
    DSU dsu(n);
    vector<pair<int, int>> points(n);
    vector<tuple<double, int, int>> dis;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        for (int j = 0; j < i; ++j) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            dis.emplace_back(dist, i, j);
        }
    }
    sort(dis.begin(), dis.end());
    for (auto [l, x, y] : dis) {
        if (dsu.merge(x, y)) {
            // cnt++;
            if (++cnt == n - k + 1) {
                cout << fixed << setprecision(2) << l << endl;
                return 0;
            }
        }
    }
}
