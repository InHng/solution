#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> points;
    vector<pair<int, int>> add, query;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        points.emplace_back(x);
        add.emplace_back(x, c);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        query.emplace_back(l, r);
        points.emplace_back(l);
        points.emplace_back(r);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    vector<int> pre(points.size() + 2);
    for (int i = 0; i < points.size(); ++i) {
        mp[points[i]] = i + 1;
    }
    for (auto [x, c] : add) {
        pre[mp[x]] += c;
    }
    for (int i = 1; i <= points.size() + 1; ++i) {
        pre[i] += pre[i - 1];
    }

    for (auto [l, r] : query) {
        l = lower_bound(points.begin(), points.end(), l) - points.begin();
        r = lower_bound(points.begin(), points.end(), r) - points.begin();
        cout << pre[r + 1] - pre[l] << endl;
    }
}
