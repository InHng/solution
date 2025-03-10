#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n;
    vector<int> all(n);
    for (int i = 0; i < n; ++i) {
        cin >> all[i];
    }
    cin >> k;
    if (k == 1) {
        cout << *max_element(all.begin(), all.end());
        return 0;
    }
    
    function<bool(int)> check = [&](int mid) -> bool {
        int cnt = 0;
        for (int x : all) {
            if (x >= mid) {
                cnt += (x - mid + k - 2) / (k - 1);
            }
        }
        return cnt > mid;
    };
    
    int left = 1, right = 0x3f3f3f3f;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left;
    return 0;
}
