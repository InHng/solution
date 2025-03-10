#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k, ans = 0, right = 1;
    string s;
    cin >> n >> k;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        pre[i] = s == "byl";
        pre[i] += pre[i - 1];
    }
    for (int left = 1; left <= n; ++left) {
        while (pre[right] - pre[left - 1] < k and right <= n) {
            ++right;
        }
        ans += n + 1 - right;
    }
    cout << ans << endl;
    return 0;
}
