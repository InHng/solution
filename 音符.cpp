#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    while (q--) {
        int t;
        cin >> t;
        cout << upper_bound(b.begin(), b.end(), t) - b.begin() << endl;
    }
    return 0;
}
