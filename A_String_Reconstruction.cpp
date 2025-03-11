#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU { // 并查集
    vector<int> pre, siz;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n + 1);
        std::iota(pre.begin(), pre.end(), 0);
        siz.assign(n + 1, 1);
    }
    
    int find(int x) {
        if (pre[x] == x) {
            return x;
        }
        return pre[x] = find(pre[x]);
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        pre[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

signed main() {
    int n, mx = 0;
    cin >> n;
    string ans(2000001, 'a');
    DSU dsu(2000001); // 并查集降低时间复杂度
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            mx = max(mx, (int)s.size() + x); // 更新答案的最长长度
            int y = dsu.find(x); // 如果这个位置已经处理过了，那么其父节点必定不是自己
            while (y < x + s.size()) {
                ans[y] = s[y - x];
                dsu.merge(y + 1, y); // 将下一个要放入的字符位置向后移，直至找到没放过的位置或超过范围
                y = dsu.find(y);
            }
        }
    }
    ans.resize(mx); // 把后面多余的字符去掉
    cout << ans << endl;
    return 0;
}
