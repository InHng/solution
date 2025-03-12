#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define lowbit(x) x & -x

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;
const int N = 4e5 + 1;

vector<int> b; // 离散化数组

int idx(int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin();
}

int tree[N];
void update(int i, int x) {
    while (i <= N) {
        tree[i] += x;
        i += lowbit(i);
    }
}

int query(int i) {
    int ans = 0;
    while (i) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        a[i].ff = i;
        cin >> a[i].ss.ff >> a[i].ss.ss;
        b.emplace_back(a[i].ss.ff);
        b.emplace_back(a[i].ss.ss);
    }
    ranges::sort(a, [](pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
        return x.ss.ff < y.ss.ff;
    });
    ranges::sort(b);
    b.erase(unique(b.begin() ,b.end()), b.end());
    for (int i = 0; i < n; ++i) {
        update(idx(a[i].ss.ss), 1);
    }
    for (int i = 0; i < n; ++i) {
        update(idx(a[i].ss.ss), -1);
        ans[a[i].ff] = query(idx(a[i].ss.ss));
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
