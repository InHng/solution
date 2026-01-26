#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    for (int i = 0; i < n; ++i) {
        vector<int> mn(n + 1);
        mn[n] = dp[n];
        for (int j = n - 1; j >= 0; --j) {
            mn[j] = min(mn[j + 1], dp[j]);
        }
        int all = count(g[i].begin(), g[i].end(), '.');
        int black = 0, white = 0;
        vector<int> dpp(n + 1);
        for (int j = 0; j <= n; ++j) {
            int cost = black + all - white;
            dpp[j] = mn[j] + cost;
            if (j < n) {
                if (g[i][j] == '#') {
                    black++;
                } else {   
                    white++;
                }
            }
        }
        dp = dpp;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
