#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<PII> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        c[i] = b[i].ff;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + c[i];
    }
    int mn = INT_MAX, k = (n + 1) / 2; 
    int best = 0, target = 0, mid = k / 2;

    for (int i = 0; i <= n - k; ++i) {
        int m = i + mid;
        int num = c[m];
        int cost_left = (m - i) * num - (pre[m] - pre[i]);
        int cost_right = (pre[i + k] - pre[m + 1]) - (i + k - m - 1) * num;
        int cnt = cost_left + cost_right;

        if (cnt < mn) {
            mn = cnt;
            best = i;
            target = num;
        }
    }

    for (int i = best; i < best + k; ++i) {
        a[b[i].ss] = target;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : "\n");
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
