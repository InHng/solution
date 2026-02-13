#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
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

Comb comb(200002);

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> cnt(2);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i * 2 <= k; ++i) {
        ans = (ans + comb.C(cnt[0], i, mod) * comb.C(cnt[1], k - i, mod) % mod) % mod;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
