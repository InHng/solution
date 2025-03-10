#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, x, y;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 每个点 向右走的花费 和 向左走的话费
    vector<int> pre(n + 2), suf(n + 2);
    pre[1] = suf[n] = 1;
    for (int i = 2; i < n; ++i) {
        pre[i] = (a[i] - a[i - 1] < a[i + 1] - a[i] ? a[i + 1] - a[i] : 1);
    }
    for (int i = n - 1; i > 1; --i) {
        suf[i] = (a[i] - a[i - 1] > a[i + 1] - a[i] ? a[i] - a[i - 1] : 1);
    }
    for (int i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }
    for (int i = n; i > 0; --i) {
        suf[i] += suf[i + 1];
    }
    cin >> m;
    while (m--) {
        cin >> x >> y;
        if (x > y) {
            cout << suf[y + 1] - suf[x + 1] << endl;
        } else {
            cout << pre[y - 1] - pre[x - 1] << endl;
        }
    }
}

signed main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
