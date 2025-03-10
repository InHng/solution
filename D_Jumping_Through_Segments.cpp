#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> op(n);
    for (pair<int, int> &opi : op) {
        cin >> opi.ff >> opi.ss;
    }

    function<bool(int)> check = [&](int mid) -> bool {
        pair<int, int> cur = {0, 0};
        for (int i = 0; i < n; ++i) {
            cur.ff = max(cur.ff - mid, op[i].ff);
            cur.ss = min(cur.ss + mid, op[i].ss);
            if (cur.ff > cur.ss) {
                return false;
            }
        }
        return true;
    };
    
    int left = 0, right = 0x3f3f3f3f;
    while (left < right) {
        int mid = (left + right) >> 1;
        pair<int, int> cur = {0, 0};
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
