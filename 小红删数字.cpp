#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(10), next_dp(10);
    for (int &ai : a) {
        cin >> ai;
    }
    if (n == 1) {
        if (a[0] < 10) {
            dp[a[0]] = 1;
        }
        for (int i = 0; i < 10; ++i) {
            cout << dp[i] << " \n"[i == 9];
        }
        return 0;
    }
    dp[a[n - 1] % 10] = 1;
    for (int i = n - 2; i >= 0; --i) {
        next_dp.assign(10, 0);
        a[i] %= 10;
        for (int j = 0; j < 10; ++j) {
            int next_add = (a[i] + j) % 10, next_mul = (a[i] * j) % 10;
            next_dp[next_add] = (next_dp[next_add] + dp[j]) % mod;
            next_dp[next_mul] = (next_dp[next_mul] + dp[j]) % mod;
        }
        dp = next_dp;
    }
    for (int i = 0; i < 10; ++i) {
        cout << dp[i] << " \n"[i == 9];
    }
}
