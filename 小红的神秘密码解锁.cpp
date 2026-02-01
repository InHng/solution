#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    string s;
    cin >> s;
    int same = 0, diff = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            same++;
        } else {
            diff++;
        }
    }
    cout << same * diff + 1 << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
