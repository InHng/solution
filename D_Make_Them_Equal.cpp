#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> d(1001, 0x3f3f3f3f); // d[i] 表示到达 i 需要的最少操作次数

// 简化为背包问题：n 个物品，体积为 d，价值为 c，填满容量为 k 的背包
void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, 12 * n);
    vector<int> a(n, 1), b(n), c(n), dp(k + 1);
    for (int &bi : b) {
        cin >> bi;
    }
    for (int &ci : c) {
        cin >> ci;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= d[b[i]]; --j) {
            dp[j] = max(dp[j], dp[j - d[b[i]]] + c[i]);
        }
    }
    cout << dp[k] << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);

    d[1] = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            int x = i + i / j;
            if (x <= 1000) {
                d[x] = min(d[x], d[i] + 1);
            }
        }
    }
    
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
