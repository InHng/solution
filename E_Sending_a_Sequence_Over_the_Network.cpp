#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) { // 该位置不是要发送的数
        if (i + b[i] <= n and dp[i - 1]) { // 长度写在它的左边
            dp[i + b[i]] = 1;
        }
        if (i - b[i] > 0 and dp[i - b[i] - 1]) { // 长度写在它的右边
            dp[i] = 1;
        }
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
