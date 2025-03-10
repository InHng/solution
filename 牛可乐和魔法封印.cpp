#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, q, x, y;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1000000005;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        x = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
        if (lower_bound(a.begin(), a.end(), y + 1) == a.end()) {
            y = n;
        } else {
            y = lower_bound(a.begin(), a.end(), y + 1) - a.begin() - 1;
        }
        cout << (y - x) << endl;
    }
    return 0;
}
