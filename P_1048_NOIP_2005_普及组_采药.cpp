#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int T, m;
    cin >> T >> m;
    vector<int> dp(T + 1);
    for (int i = 0; i < m; ++i) {
        int t, w;
        cin >> t >> w;
        for (int j = T; j >= t; --j) {
            dp[j] = max(dp[j], dp[j - t] + w);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
