#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

struct monster {
    int id;
    int x, y;
    long double angle;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<monster> monsters(n);
    for (int i = 0; i < n; ++i) {
        monsters[i].id = i;
        cin >> monsters[i].x >> monsters[i].y;
        monsters[i].angle = atan2l(monsters[i].y, monsters[i].x);
    }
    sort(monsters.begin(), monsters.end(), [&](monster a, monster &b) {
        return a.angle < b.angle;
    });
    vector<int> cnt;
    vector<int> original_idx(n);
    cnt.emplace_back(1);
    original_idx[monsters[0].id] = 0;
    int now = 0;
    for (int i = 1; i < n; ++i) {
        if (monsters[i].angle == monsters[i - 1].angle) {
            cnt[now]++;
        } else {
            now++;
            cnt.emplace_back(1);
        }
        original_idx[monsters[i].id] = now;
    }
    vector<int> pre(cnt.size() + 1, 0);
    for (int i = 0; i < cnt.size(); ++i) {
        pre[i + 1] = pre[i] + cnt[i];
    }
    while (q--) {
        int left, right;
        cin >> left >> right;
        left--, right--;
        int original_left = original_idx[left], original_right = original_idx[right];
        if (original_left >= original_right) {
            cout << pre[original_left + 1] - pre[original_right] << endl;
        } else {
            cout << pre[original_left + 1] - pre[0] + pre[cnt.size()] - pre[original_right] << endl;
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
