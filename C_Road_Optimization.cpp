#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n + 1), a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    d[n] = l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int dp[n + 1][k + 1]; // dp[i][j] 表示前 i 个标志删除了 j 个标志
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) { // 当前位置为 i
        for (int j = 0; j <= k; ++j) { // 此时一共删除了 j 个标志
            for (int k = i - 1; k >= 0; --k) { // 将 k -> i 中间的标志全部删除
                int last_j = j - (i - k - 1); // 将 k -> i 中间的标志全部删除前，删除了多少标记
                if (last_j >= 0) {
                    dp[i][j] = min(dp[i][j], dp[k][last_j] + a[k] * (d[i] - d[k]));
                }
            }
        }
    }
    int mn = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i) {
        mn = min(mn, dp[n][i]);
    }
    cout << mn;
    return 0;
}
