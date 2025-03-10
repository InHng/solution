#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int L, n, m;
    cin >> L >> n >> m;
    vector<int> all(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> all[i];
    }
    all.push_back(L);
    
    function<bool(int)> check = [&](int mid) -> bool {
        int cnt = 0, i = 0, now = 0;
        while (i <= n) {
            i++;
            if (all[i] - all[now] < mid) {
                cnt++;
            } else {
                now = i;
            }
        }
        return cnt <= m;
    };
    
    int left = 1, right = 0x3f3f3ff3;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << left;
    return 0;
}
