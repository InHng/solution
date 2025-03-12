#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int dp[n][3]; // dp[i][j] 表示第 i 个位置增加 j 的消费
    dp[0][0] = 0, dp[0][1] = b[0], dp[0][2] = b[0] * 2;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) { // 第 i 个位置的数字增加 j
            dp[i][j] = 0x3f3f3f3f3f3f3f3f;
            for (int k = 0; k < 3; ++k) {
                if (a[i - 1] + k != a[i] + j) { // 第 i - 1 个位置的数字增加 k
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
            }
        }
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
