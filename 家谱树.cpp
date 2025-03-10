#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, x;
    cin >> n;
    vector<int> g[n + 1];
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        while (true) {
            cin >> x;
            if (!x) {
                break;
            }
            g[i].emplace_back(x);
            cnt[x]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!cnt[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : g[u]) {
            if (--cnt[v] == 0) {
                q.push(v);
            } 
        }
    }
    return 0;
}
