#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m, x, ans = 0, cnt = 0;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt += a[i];
        if (i >= m) {
            cnt -= a[i - m];
        }
        if (cnt > x) {
            ans += cnt - x;
            a[i] -= cnt - x;
            cnt = x;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
