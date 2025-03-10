#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

int ksm(int a, int b, int mod) {
    a %= mod;
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << ksm(a, b, p) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
