#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, k, x, cnt = 0;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = n - k; i < n; ++i) {
        cnt += a[i];
        if (cnt >= x) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
