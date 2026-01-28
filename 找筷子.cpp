#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, ans = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    
    return 0;
}
