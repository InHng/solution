#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
signed main() {
    int n, r;
    cin >> n >> r;
    r = min(5001ll, r);
    int ans = 0;
    int all[5005][5005];
    for (int i = 0; i < n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        all[++x][++y] += v;
    }
    for (int i = 1; i <= 5001; ++i) {
        for (int j = 1; j <= 5001; ++j) {
            all[i][j] += all[i - 1][j] + all[i][j - 1] - all[i - 1][j - 1];
            if (i >= r and j >= r) {
                ans = max(ans, all[i][j] - all[i - r][j] - all[i][j - r] + all[i - r][j - r]);
            }
        }
    }
    cout << ans;
    return 0;
}
