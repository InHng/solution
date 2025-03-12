#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> g(n);
    for (string &gi : g) {
        cin >> gi;
        gi = " " + gi;
    }
    if (m < x or (m > y and m < 2 * x)) { // 所有都涂成一个颜色都不能满足题意
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(m + 1); // 每一列的黑色方块数量前缀和
    for (int j = 1; j <= m; ++j) {
        for (int i = 0; i < n; ++i) {
            a[j] += (g[i][j] == '#');
        }
        a[j] += a[j - 1];
    }
    // dp[i][j] 表示从第一列到第 i 列， 最后一列是 j 的重绘个数
    int dp[m + 1][2]; // 其中 j = 0 时表示 '.'，j = 1 时表示 '#'
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = x; i <= min(m, y); ++i) { // 前 y 列涂成一个颜色
        dp[i][0] = i * n - a[i];
        dp[i][1] = a[i];
    }
    for (int i = 2 * x; i <= m; ++i) { // 最小为 2 个 x 宽度
        for (int j = x; j <= y; ++j) { // 最小长度为 x ，最大宽度为 y
            int l = i - j;
            if (l < x) { // 如果前一段不能满足条件了
                break;
            }
            dp[i][0] = min(dp[i][0], dp[l][1] + (j * n - (a[i] - a[l])));
            dp[i][1] = min(dp[i][1], dp[l][0] + (a[i] - a[l]));
        }
    }
    cout << min(dp[m][0], dp[m][1]) << endl;
    return 0;
}
