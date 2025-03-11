#include <bits/stdc++.h>
using namespace std;

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
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--) {
        string op;
        int a, b;
        cin >> op >> a;
        if (op == "C") {
            cin >> b;
            dsu.merge(a, b);
        } else if (op == "Q1") {
            cin >> b;
            cout << (dsu.same(a, b) ? "Yes" : "No") << endl; 
        } else {
            cout << dsu.size(a) << endl;
        }
    }
    return 0;
}
