#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 2000120420010122;

string s;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    while (cin >> s) {
        int dpc = 0, dpcw = 0, dpcwb = 0, ans = 0;
        for (char &c : s) {
            c = tolower(c);
            if (c == 'c') {
                dpc += 1;
                ans += dpcwb;
            } else if (c == 'w') {
                dpcw += dpc;
            } else if (c == 'b') {
                dpcwb += dpcw;
            }
        }
        cout << ans % mod << endl;
    }
    return 0;
}
