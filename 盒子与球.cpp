#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 1e9 + 7; // 998244353;

// C a 取 b = fact[a] * infact[b - a] * infact[b]，注意取余
struct Comb {
    vector<int> fact, infact;

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
    
    Comb() {}
    Comb(int n) {
        fact.resize(n + 1);
        infact.resize(n + 1);
        fact[0] = infact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            infact[i] = infact[i - 1] * ksm(i, mod - 2, mod) % mod;
        }
    }

    int C(int a, int b, int mod) { // C a 取 b，对 mod 取余
        if (a < b) {
            return 0;
        }
        return fact[a] * infact[a - b] % mod * infact[b] % mod;
    }
};

void solve() {
    int n, r, ans = 0;
    cin >> n >> r;
    Comb comb(r);
    for (int i = 0; i < r; ++i) {
        if (i & 1) {
            ans -= comb.C(r, i, mod) * comb.ksm(r - i, n, mod) % mod;
        } else {
            ans += comb.C(r, i, mod) * comb.ksm(r - i, n, mod) % mod;
        }
    }
    cout << ans % mod << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
