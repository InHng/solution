#include <bits/stdc++.h>
using namespace std;

#define int long long

// 只有四种攻击方式 RL RLL RRL RRLL
void solve() {
    int n, ans = 0x3f3f3f3f;
    string s;
    cin >> n >> s;
    s = "$" + s;
    for (int i = 1; i <= 4; ++i) {
        int dp[n + 1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int j = 2; j <= n; ++j) {
            // 攻击方式 RL
            dp[j] = min(dp[j], dp[j - 2] + (s[j] != 'L') + (s[j - 1] != 'R'));
            if (j >= 3) { // 攻击方式 RXL
                dp[j] = min(dp[j], dp[j - 3] + (s[j] != 'L') + (s[j - 2] != 'R'));
            }
            if (j >= 4) { // 攻击方式 RRLL
                dp[j] = min(dp[j], dp[j - 4] + (s[j] != 'L') + (s[j - 1] != 'L') + (s[j - 2] != 'R') + (s[j - 3] != 'R'));
            }
        }
        ans = min(ans, dp[n]);
        rotate(s.begin() + 1, s.begin() + 2, s.end()); // 使字符串循环左移一位
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
