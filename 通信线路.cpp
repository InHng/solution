#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<pair<int, int>> g[n + 1];
    while (p--) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].emplace_back(l, b);
        g[b].emplace_back(l, a);
    }

    function<bool(int)> check = [&](int mid) -> bool {
        vector<int> dist(n + 1, INF);
        vector<bool> memo(n + 1, false);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 1);
        while (q.size()) {
            auto [dis, u] = q.top();
            q.pop();
            if (memo[u]) {
                continue;
            }
            memo[u] = true;
            for (pair<int, int> edge : g[u]) {
                // 大于最小花费的让电话公司花钱
                int v = edge.ss, dis = edge.ff > mid;
                if (dist[v] > dist[u] + dis) {
                    dist[v] = dist[u] + dis;
                    q.emplace(dist[v], v);
                }
            }
        }
        return dist[n] <= k;
    };

    int left = -1, right = 1000001;
    while (left + 1 < right) { // 二分最小花费
        int mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (right == 1000001) {
        right = -1;
    }
    cout << right;
    return 0;
}
