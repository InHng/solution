#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) {
        int x, y;
        cin >> x >> y;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        int left = x, right = 2e9 + 1;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            int idy = lower_bound(a.begin(), a.end(), mid) - a.begin();
            if (x + y + idy - idx <= mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << left << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
