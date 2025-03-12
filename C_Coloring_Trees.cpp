#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, k, mn = 0, ans = 0x3f3f3f3f3f3f3f3f;
    cin >> n >> m >> k;
    // dp[i][j][k] 表示前 i 棵树的最后一棵树涂第 j 种颜色，并且涂成 k 个相同连续段的最小花费
    int p[n + 1][m + 1], dp[n + 1][m + 1][n + 1];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0][0] = 0;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> p[i][j];
            if (c[i]) {
                p[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= i; ++k) {
                if (c[i + 1]) { // 如果下一个位置已经涂了颜色，那么下一个位置只有一种涂法
                    dp[i + 1][c[i + 1]][k + (c[i + 1] != j)] = min(dp[i + 1][c[i + 1]][k + (c[i + 1] != j)], dp[i][j][k]);
                } else { // 如果没有颜色，就把每个颜色都试着涂一遍
                    for (int color = 1; color <= m; ++color) {
                        dp[i + 1][color][k + (color != j)] = min(dp[i + 1][color][k + (color != j)], dp[i][j][k] + p[i + 1][color]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        ans = min(ans, dp[n][i][k]);
    }
    cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << endl;
    return 0;
}
