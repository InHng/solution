#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;
    vector<int> a(m), b(m), c(m), d(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> dp(n + 1); // dp[i] 表示用掉 i 克面团最多可以获得多少钱
    for (int i = 0; i <= n; ++i) { // 全做不带馅的面包
        dp[i] = (i / c0) * d0;
    }
    for (int i = 0; i < m; ++i) { // 遍历每种面包的制作
        for (int j = 1; j <= a[i] / b[i]; ++j) { // 最多可以做 a_i / b_i 个
            for (int k = n; k >= c[i]; --k) { // 最少需要 c_i 克面团
                dp[k] = max(dp[k], dp[k - c[i]] + d[i]);
            }
        }
    }
    cout << dp[n];
    return 0;
}
