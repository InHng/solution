#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, k, ans = 1;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    while (2 * ans <= n) {
        ans <<= 1;
    }
    cout << ans * 2 - 1 << endl;
    
    return 0;
}
