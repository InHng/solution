#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    int ans = 0;
    string s, t;
    cin >> s >> t;
    int l1 = s.size(), l2 = t.size();
    int dp[l1 + 1][l2 + 1]; // dp[i + 1][j + 1] 表示以 s[i] 和 t[j] 结尾的方案数
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            // 如果两个位置相等，那么之前位置的值也需要加过来
            dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % mod;
        }
    }
    for (int i = 0; i < l1; ++i) {
        ans = (ans + dp[i + 1][l2]) % mod;
    }
    cout << ans << endl;
    return 0;
}
