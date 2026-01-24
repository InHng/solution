#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0x3f3f3f3f;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<vector<int>>> dp(1 << n, vector<vector<int>>(n, vector<int>(4, 0x3f3f3f3f)));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i][0] = 0;
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (not ((i >> j) & 1)) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (j == k or not (i >> k & 1)) {
                    continue;
                }
                int last = i - (1 << j);
                for (int l = 0; l < 4; ++l) {
                    dp[i][j][l] = min(dp[i][j][l], dp[last][k][l] + g[k][j]);
                }
                dp[i][j][1] = min(dp[i][j][1], dp[last][k][0]);
                dp[i][j][2] = min(dp[i][j][2], dp[last][k][0] + g[k][j] * 2);
                dp[i][j][3] = min(dp[i][j][3], dp[last][k][1] + g[k][j] * 2);
                dp[i][j][3] = min(dp[i][j][3], dp[last][k][2]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i][3]);
    }
    cout << ans << endl;
    return 0;
}
