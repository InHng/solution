#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int ksm(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int left = 0, right = pow(2e18, 1.0 / k);
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (n - ksm(mid, k) >= 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (ksm(right, k) - n < n - ksm(left, k)) {
        cout << right << endl;
    } else {
        cout << left << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
