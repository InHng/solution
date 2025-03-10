#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> all(n);
    for (int i = 0; i < n; ++i) {
        cin >> all[i];
    }
    
    function<bool(int)> check = [&](int mid) -> bool {
        int cnt = 0;
        for (int x : all) {
            if (x < mid) {
                cnt += mid - x;
            }
        }
        return cnt <= min(mid, m);
    };
    
    int left = 1, right = 0x3f3f3f3f;
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
