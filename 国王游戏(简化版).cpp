#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>

void solve() {
    int n, ans = 0, now = 1;
    cin >> n;
    vector<PII> ab(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> ab[i].ff >> ab[i].ss;
    }
    sort(ab.begin(), ab.end(), [](const PII &a, const PII &b) {
        return a.ff * a.ss < b.ff * b.ss;
    });
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, now / ab[i].ss);
        now *= ab[i].ff;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
