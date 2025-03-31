#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, V;
    cin >> n >> V;
    vector<int> dp(V + 1);
    for (int i = 0; i < n; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = v; j <= V; ++j) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
