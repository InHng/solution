#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int m, n;
    cin >> m >> n;
    vector<int> dp(m + 1);
    for (int i = 0; i < n; ++i) {
        int p, t;
        cin >> p >> t;
        for (int j = t; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j - t] + p);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
