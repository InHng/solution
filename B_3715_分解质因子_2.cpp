#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                cout << i << ' ';
            }
        }
        if (n != 1) {
            cout << n;
        }
        cout << endl;
    }
    
    return 0;
}
