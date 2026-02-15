#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 2), pre(n + 2), rear(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        int diff = min(b[i], b[i - 1]);
        pre[i] += diff;
        b[i] -= diff;
    }
    b = a;
    for (int i = n; i; --i) {
        rear[i] = rear[i + 1];
        int diff = min(b[i], b[i + 1]);
        rear[i] += diff;
        b[i] -= diff;
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, pre[i - 1] + a[i] + rear[i + 1]);
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
