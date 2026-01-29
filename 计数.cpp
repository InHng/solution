#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 1e9 + 7;

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
    int n, ans = 1, last = 0;
    cin >> n;
    vector<int> a(n + 2);
    Comb comb(1000 + n);
    a[0] = 1000, a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i]) {
            int diff = a[last] - a[i], cnt_0 = i - last - 1;
            ans = (ans * comb.C(diff + cnt_0, cnt_0, mod)) % mod;
            last = i;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
