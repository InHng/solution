#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    int left = 0, right = 0; // 左右指针
    int cnt = 0; // 当前总和
    int ans = 0; // 最终答案
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    while (right < n) {
        cnt += a[right++]; // 加上右指针所在位置的数
        if (cnt >= k) { // 如果满足条件了，就寻找左边界
            while (cnt >= k) {
                cnt -= a[left++];
            }
        }
        ans += left; // 加上所有满足条件的数量(左边界左边都可以)
    }
    cout << ans << endl;
    return 0;
}
