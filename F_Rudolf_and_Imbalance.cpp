#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k);
    for (int &ai : a) {
        cin >> ai;
    }
    for (int &di : d) {
        cin >> di;
    }
    for (int &fi : f) {
        cin >> fi;
    }
    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    function<bool(int)> check = [&](int mid) -> bool {
        int cnt = 0, idx = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > mid) {
                if (++cnt > 1) { // 需要分割的区间最多只能有一个
                    return false;
                } 
                idx = i;
            }
        }
        if (not cnt) { // 已经满足条件
            return true;
        }
        int down = a[idx] - mid, up = a[idx - 1] + mid; // 肯定是把数组塞到这个区间内
        for (int left = 0, right = k - 1; left < m; ++left) {
            while (~right and d[left] + f[right] > up) {
                --right;
            }
            if (~right and d[left] + f[right] >= down) {
                return true;
            }
        }
        return false;
    };

    
    int left = 0, right = 2e9 + 1;
    while (left + 1 < right) { // 二分答案
        int mid = (left + right) >> 1;
        (check(mid) ? right : left) = mid;
    }
    cout << left + 1 << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
