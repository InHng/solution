#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    if (n == 1) {
        cout << 9 << endl;
        return 0;
    }
    vector<int> a(n);
    int dp[n][10]; // dp[i][j] 表示第 i 位上为 j 时的方案数
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {   // 第 i 位上
        for (int j = 0; j < 10; ++j) {  // 的数字是 j
            dp[i + 1][(j + a[i + 1]) / 2] += dp[i][j];
            if ((j + a[i + 1]) / 2 != (j + a[i + 1] + 1) / 2) {
                dp[i + 1][(j + a[i + 1] + 1) / 2] += dp[i][j];
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        ans += dp[n - 1][i];
    }
    for (int i = 1; i < n; ++i) { // 如果其中有和原来字符串一样的方案
        if (abs(a[i] - a[i - 1]) > 1) {
            break;
        } else if (i == n - 1) {
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}
