#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    priority_queue<array<int, 4>> q;
    q.push({a[1] * k, 1, 0, k});
    for (int i = 0; i < x; ++i) {
        auto [mx, id, pre, cnt] = q.top();
        q.pop();
        cout << mx << endl;
        if (pre) {
            q.push({mx - a[id - 1] + a[id], id, pre - 1, cnt + 1});
        }
        if (id < n) {
            q.push({mx - a[id] + a[id + 1], id + 1, cnt - 1, 1});
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
