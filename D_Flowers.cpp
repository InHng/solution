#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

signed main() {
    int t, k;
    cin >> t >> k;
    // dp 表示当前长度的花有多少种取法，pre 表示前缀和
    vector<int> dp(1e5 + 5), pre(1e5 + 5);
    for (int i = 1; i <= k; ++i) { // 前 k 个花由于不能组成连续 k 个白花，所以只能放红花
        ++dp[i];
        pre[i] = pre[i - 1] + dp[i];
    }
    // 前 k 个花全是白花
    ++dp[k];
    ++pre[k];
    for (int i = k + 1; i < 1e5 + 5; ++i) {
        // 由前一个位置增加一个红花，或前 k 朵花都是白花
        dp[i] = (dp[i - 1] + dp[i - k]) % mod;
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (pre[b] - pre[a - 1] + mod) % mod << endl;
    }
    
    return 0;
}
