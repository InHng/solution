#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, ans = INF;
    string s;
    cin >> n >> s;
    s = "F" + s;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].ff >> v[i].ss;
    }

    function<void(int, int)> dfs = [&](int i, int cnt) {
        if (v[i].ff == 0 and v[i].ss == 0) {
            ans = min(ans, cnt);
        }
        if (v[i].ff) {
            dfs(v[i].ff, cnt + (s[i] != 'L'));
        }
        if (v[i].ss) {
            dfs(v[i].ss, cnt + (s[i] != 'R'));
        }
    };

    dfs(1, 0);
    cout << ans << endl;
}

signed main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
