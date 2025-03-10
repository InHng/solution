#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ans = 0, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
}

int main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
