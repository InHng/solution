#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

// 给出一个序列，每次可以移动一个数到任意一个位置，问最少多少次能使得序列非降，考虑有多少数不用动即可
signed main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, double>> a(n + 1); 
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].ff >> a[i].ss;
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i].ff >= a[j].ff) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << n - ans << endl;
    return 0;
}
