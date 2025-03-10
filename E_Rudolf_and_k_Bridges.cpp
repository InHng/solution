#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        vector<int> a(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[j];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(1, 0);
        for (int j = 1; j < m; ++j) {
            while (q.size() and q.top().ss < j - d - 1) {
                q.pop();
            }
            q.emplace(q.top().ff + a[j] + 1, j);
        }
        while (q.size() and q.top().ss != m - 1) {
            q.pop();
        }
        pre[i] = q.top().ff;
    }
    int cnt = accumulate(pre.begin(), pre.begin() + k, 0ll);
    int ans = cnt;
    for (int i = k; i < n; ++i) {
        cnt += pre[i] - pre[i - k];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
