#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int &si : s) {
        cin >> si;
    }
    ranges::sort(s); // 想要差值最小必定是取一个连续的区间
    int dp[n][n]; // dp[i][j] 表示取 i 到 j 学生的最小差值
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; ++i) { // 第 i + 1 天
        for (int j = 0; j < n - i; ++j) { // 从 j 学生开始取 i 个人
            int left = j, right = j + i;
            dp[left][right] = s[right] - s[left] + min(dp[left + 1][right], dp[left][right - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
