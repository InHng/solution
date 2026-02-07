#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, d, l = 0, ans = 0;
    cin >> n >> d;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int low = a[i] - d + 1, high = a[i] + d - 1;
        multiset<int>::iterator it = s.lower_bound(low);
        while (it != s.end() and *it <= high) {
            s.erase(s.find(a[l++]));
            it = s.lower_bound(low);
        }
        s.insert(a[i]);
        ans += i - l + 1;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
