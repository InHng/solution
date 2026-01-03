#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

signed main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF), best(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        dp[i] = best[x] + 1;
        best[x] = min(best[x], dp[i - 1]);
    }
    cout << (dp[n] > n ? -1 : dp[n]) << endl;
    return 0;
}
