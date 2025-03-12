#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    int k, x = 0;
    string start, end;
    cin >> start >> end >> k;
    int n = start.size();
    // dp[i][0] 表示分割 i 次变成了 end 的方案数
    // dp[i][1] 表示分割 i 次没变成 end 的方案数
    int dp[k + 1][2];
    memset(dp, 0, sizeof(dp));
    (start == end ? dp[0][0] : dp[0][1]) = 1;
    for (int i = 0; i < n; ++i) { // 从 i 这个位置开始分割串
        int flag = 1;
        for (int j = 0; j < n; ++j) { // 判断从 i 位置分割串能否成立
            if (start[(i + j) % n] != end[j]) {
                flag = 0;
                break;
            }
        }
        x += flag;
    }
    for (int i = 0; i < k; ++i) {
        // 其他串通过一次变换得到 x 个 end，每个原串通过一次变换得到除了自己以外的 x - 1 个其他原串
        dp[i + 1][0] = (x * dp[i][1] + (x - 1) * dp[i][0]) % mod;
        // 其他串通过一次变换得到 n - x 个其他串，每个原串通过一次变换得到除了自己以外的 n - x - 1 个其他串
        dp[i + 1][1] = ((n - x) * dp[i][0] + (n - x - 1) * dp[i][1]) % mod;
    }
    cout << dp[k][0] << endl;
    return 0;
}
