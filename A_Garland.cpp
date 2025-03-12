#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, cnt[2] = {0, 0};
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        cnt[i & 1]++;
    }
    // dp[i][j][k] 表示前 i 个数有 j 个偶数且最末尾为 k(0 表示偶数，1 表示奇数) 的最小结果
    int dp[n + 1][cnt[0] + 2][2]; // 第二维取 +2 防止越界
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < min(i, cnt[0] + 1); ++j) {
            for (int k = 0; k < 2; ++k) {
                if (p[i]) { // 如果这个位置数字已经固定，则只有一种取法
                    if (p[i] & 1) {
                        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + (k ^ 1));
                    } else {
                        dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i - 1][j][k] + (k & 1));
                    }
                } else { // 否则在这个位置判断是奇数还是偶数
                    for (int l = 0; l < 2; ++l) {
                        dp[i][j + 1 - l][l] = min(dp[i][j + 1 - l][l], dp[i - 1][j][k] + (k ^ l));
                    }
                }
            }
        }
    }
    cout << min(dp[n][cnt[0]][0], dp[n][cnt[0]][1]) << endl;
    return 0;
}
