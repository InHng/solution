#include <bits/stdc++.h>
using namespace std;

#define int long long

// 操作一就是差分使 diff[1] - 1, diff[i + 1] + 1
// 操作二就是差分使 diff[i] - 1, diff[n + 1] + 1
// 要使得 diff[2 ~ n] 都为 0
// 所以就是 第一个数的大小需要 >= 后面差分数的负数的绝对值之和
void solve() {
    int n, cnt = 0;;
    cin >> n;
    vector<int> a(n + 1), diff(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    for (int i = 2; i <= n; ++i) {
        if (diff[i] < 0) {
            cnt -= diff[i];
        }
    }
    cout << (cnt <= a[1] ? "YES" : "NO") << endl;
}
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
