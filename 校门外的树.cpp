#include <bits/stdc++.h>
using namespace std;

#define ing long long

signed main() {
    int L, M;
    cin >> L >> M;
    vector<int> a(L + 2);
    while (M--) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    int ans = (a[0] == 0);
    for (int i = 1; i <= L; ++i) {
        a[i] += a[i - 1];
        ans += (a[i] == 0);
    }
    cout << ans << endl;
}
