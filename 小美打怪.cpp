#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main() {
    int n, H, A, ans = 0;
    cin >> n >> H >> A;
    vector<pair<int, int>> moster(n);
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> moster[i].ff;
    }
    for (int i = 0; i < n; ++i) {
        cin >> moster[i].ss;
    }
    sort(moster.begin(), moster.end());
    for (int i = 0; i < n; ++i) {
        if (H <= moster[i].ff or A <= moster[i].ss) {
            continue;
        }
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (H <= moster[j].ff or A <= moster[j].ss) {
                continue;
            }
            if (moster[j].ff < moster[i].ff and moster[j].ss < moster[i].ss) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
