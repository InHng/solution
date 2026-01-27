#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

struct Tree {
    vector<int> tree;
    
    Tree() {}
    Tree(int n) {
        tree.resize(n + 10);
    }
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void update(int i, int x) {
        while (i < tree.size()) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int ans = 0;
        while (i) {
            ans += tree[i];
            i -= lowbit(i);
        }
        return ans;
    }

    int sum(int left, int right) {
        return query(right) - query(left);
    }
};

void solve() {
    int n, ans = 0, cnt = 0;
    string s;
    cin >> n >> s;
    Tree tree(2 * n + 10);
    tree.update(n + 1, 1);
    for (char c : s) {
        if (c == 'A') {
            cnt += 1;
        } else if (c == 'B') {
            cnt -= 1;
        }
        tree.update(cnt + n + 1, 1);
        ans += tree.query(cnt + n);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
