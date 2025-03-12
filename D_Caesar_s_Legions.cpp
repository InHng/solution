#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e8;

signed main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    // dp[i][j][k] 表示当前使用了 i 个步兵和 j 个骑兵，且队伍末尾为 k (0 表示步兵，1 表示骑兵)
    int dp[n1 + 1][n2 + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= min(n1, k1); i++) { // 在满足条件的情况下全部排步兵
        dp[i][0][0] = 1;
    }
    for (int i = 0; i <= min(n2, k2); i++) { // 在满足条件的情况下全部排骑兵
        dp[0][i][1] = 1;
    }
    
    for (int i = 1; i <= n1; ++i) { // 
        for (int j = 1; j <= n2; ++j) {
            // 此时使用了 i 个步兵和 j 个骑兵
            for (int k = 1; k <= min(i, k1); ++k) { // 末尾有 k 个连续的步兵
                dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % mod;
            }
            for (int k = 1; k <= min(j, k2); ++k) { // 末尾有 k 个连续的骑兵
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % mod;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << endl;
    return 0;
}
