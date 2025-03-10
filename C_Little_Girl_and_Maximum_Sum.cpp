#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> a(n), diff(n + 2), cnt;
    for (int &ai : a) {
        cin >> ai;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        cnt.emplace_back(diff[i]);
    }
    ranges::sort(cnt, greater());
    ranges::sort(a, greater());
    for (int i = 0; i < n; ++i) {
        ans += cnt[i] * a[i];
    }
    cout << ans << endl;
    return 0;
}
