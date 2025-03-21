#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, cnt = 0;
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
    for (int i = 0; i < points.size(); ++i) {
        cout << points[i] << " \n"[i == points.size() - 1];
    }
    for (int i = 0; i < pre.size(); ++i) {
        cout << pre[i] << " \n"[i == pre.size() - 1];
    }

    function<int(int)> find = [&](int x) -> int {
        int left = -1, right = points.size();
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (points[mid] > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left + 1;
    };

    for (auto [l, r] : query) {
        l = find(l);
        r = find(r);
        cout << l<< " " << r << endl;
        cout << pre[r] - pre[l - 1] << endl;
    }
}
