#include <bits/stdc++.h>
using namespace std;

#define int long long

// 本题有点离散化的意思，数的范围过大，用数组存储会出现内存过大
// 由于最多给出 1e5 个数，所以可以用 map 搭建起一个映射关系来减少内存消耗
signed main() {
    int n, ans = 0, all = 0;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int x;
        char c;
        cin >> x >> c;
        if (c == '.') { // 裁判说数一样，那么裁判说对的取值范围是[a,a]
            mp[x]++;
            mp[x + 1]--;
        } else if (c == '+') { // 裁判说数大了，那么裁判说对的取值范围是(-∞,a]
            mp[x]--;
            mp[-INT_MAX]++;
        } else { // 裁判说数小了，那么裁判说对的取值范围是[a,+∞)
            mp[x + 1]++;
        }
    }
    for (auto [_, x] : mp) { // 对差分前缀和
        ans = max(ans, all += x);
    }
    cout << ans;
    return 0;
}
