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
        while (i <= tree.size()) {
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Tree tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tree.update(i, a[i]);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            tree.update(x, a[x + 1] - a[x]);
            tree.update(x + 1, a[x] - a[x + 1]);
            swap(a[x], a[x + 1]);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.sum(l - 1, r) << endl;
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
