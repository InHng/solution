#include <bits/stdc++.h>
using namespace std;

#define ing long long

signed main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int A, B;
        cin >> A >> B;
        a.emplace_back(A);
        b.emplace_back(B);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        ans += b[i] - a[i];
        if (i and a[i] < b[i - 1]) {
            ans -= b[i - 1] - a[i];
        }
    }
    cout << ans;
}
