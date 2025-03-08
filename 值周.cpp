#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int L, M;
    cin >> L >> M;
    int ans = 0;
    vector<int> diff(L + 1, 0);
    while (M--) {
        int l, r;
        cin >> l >> r;
        diff[l]--;
        diff[r + 1]++;
    }
    for (int i = 0; i <= L; ++i) {
        if (i) {
            diff[i] += diff[i - 1];
        }
        if (diff[i] == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
