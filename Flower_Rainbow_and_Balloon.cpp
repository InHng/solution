#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

bool check(string s, int len, int m, int k) {
    int bai = 0, hong = 0, huang = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'r') {
            hong += 1;
        } else if (s[i] == 'y') {
            huang += 1;
        } else {
            bai += 1;
        }
    }
    if (2 * min(bai, m) + max(2 * hong + huang, 2 * huang + hong) >= k) {
        return true;
    }
    for (int i = len; i < s.size(); ++i) {
        if (s[i] == 'r') {
            hong += 1;
        } else if (s[i] == 'y') {
            huang += 1;
        } else if (s[i] == 'w') {
            bai += 1;
        }
        if (s[i - len] == 'r') {
            hong -= 1;
        } else if (s[i - len] == 'y') {
            huang -= 1;
        } else if (s[i - len] == 'w') {
            bai -= 1;
        }
        if (2 * min(bai, m) + max(2 * hong + huang, 2 * huang + hong) >= k) {
            return true;
        }
    }
    return false;
};

void solve() {
    int n, m, k, ans = -1;
    string s;
    cin >> n >> m >> k >> s;
    int left = 0, right = n + 1;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (check(s, mid, m, k)) {
            right = mid;
            ans = mid;
        } else {
            left = mid;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
