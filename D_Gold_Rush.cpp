#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

bool dfs(int x) {
    if (x % 3) {
        return false;
    }
    int a = x * 2 / 3, b = x / 3;
    if (a == m or b == m) {
        return true;
    }
    if (a < m and b < m) {
        return false;
    }
    return ((a > m and dfs(a)) or (b > m and dfs(b)));
}

void solve() {
    cin >> n >> m;
    if (m == n) {
        cout << "YES\n";
    } else if (m > n) {
        cout << "NO\n";
    } else {
        cout << (dfs(n) ? "YES" : "NO") << endl;
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
