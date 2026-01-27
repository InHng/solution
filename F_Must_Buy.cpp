#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m;
    string ans;
    cin >> n >> m;
    vector<int> p(n + 1), v(n + 1);
    vector<vector<int>> dp1(n + 2, vector<int>(m + 1, 0)), dp2(n + 2, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> v[i];
        for (int j = m; j >= 0; --j) {
            if (j >= p[i]) {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - p[i]] + v[i]);
            } else {
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 0; --j) {
            if (j >= p[i]) {
                dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - p[i]] + v[i]);
            } else {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
            }
        }
    }
    int maxv = dp1[n][m];
    for (int i = 1; i <= n; ++i) {
        int target = maxv - v[i], w = m - p[i];
        bool C = true;
        for (int j = 0; j <= w; ++j) {
            if (dp1[i - 1][j] + dp2[i + 1][w - j] >= target) {
                C = false;
                break;
            }
        }
        if (C) {
            ans += 'C';
        } else {
            bool A = true;
            for (int j = 0; j <= m; ++j) {
                if (dp1[i - 1][j] + dp2[i + 1][m - j] == maxv) {
                    A = false;
                    break;
                }
            }
            ans += (A ? "A" : "B");
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
