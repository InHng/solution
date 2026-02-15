#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 998244353;

struct DSU { // 并查集
    vector<int> pre, siz;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n + 1);
        iota(pre.begin(), pre.end(), 0);
        siz.assign(n + 1, 1);
    }
    
    int find(int x) {
        if (pre[x] == x) {
            return x;
        }
        return pre[x] = find(pre[x]);
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        } else if (siz[x] < siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        pre[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

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
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    DSU dsu(n);
    vector<int> idx(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            idx[i] = cnt;
            st.emplace(cnt++);
        } else {
            idx[i] = st.top();
            st.pop();
        }
    }
    cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            cnt += dsu.merge(idx[i], idx[i + 1]);
        }
    }
    cout << ksm(2, n / 2 - cnt, mod) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
