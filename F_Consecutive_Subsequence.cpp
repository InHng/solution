#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, cnt = 0, x = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> dp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (dp[a[i]] > cnt) {
            cnt = dp[a[i]];
            x = a[i];
        }
    }
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == x) {
            ans.emplace_back(i + 1);
            --x;
        }
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    return 0;
}
