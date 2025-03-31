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
    int x, y, g, ans = 0;
    cin >> x;
    vector<pair<string, string>> s, ns;
    vector<tuple<string, string, string>> group;
    map<string, int> mp;
    for (int i = 0; i < x; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        s.emplace_back(name1, name2);
    }
    cin >> y;
    for (int i = 0; i < y; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        ns.emplace_back(name1, name2);
    }
    cin >> g;
    for (int i = 0; i < g; ++i) {
        string name1, name2, name3;
        cin >> name1 >> name2 >> name3;
        mp[name1] = i * 3;
        mp[name2] = i * 3 + 1;
        mp[name3] = i * 3 + 2;
        group.emplace_back(name1, name2, name3);
    }
    // --- 先全部存起来, 从这里开始进行判断 ---
    DSU dsu(mp.size());
    for (auto [name1, name2, name3] : group) {
        dsu.merge(mp[name1], mp[name2]);
        dsu.merge(mp[name1], mp[name3]);
    }
    for (auto [name1, name2] : s) {
        ans += dsu.same(mp[name1], mp[name2]) == 0;
    }
    for (auto [name1, name2] : ns) {
        ans += dsu.same(mp[name1], mp[name2]);
    }
    cout << ans << endl;
}
