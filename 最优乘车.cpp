#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    int m, n;
    cin >> m >> n;
    vector<int> g[n + 1];
    m++;
    while (m--) { // 造图
        string s;
        getline(cin, s); // 获取一条线路
        vector<int> a;
        for (int i = 0; i < s.size(); ++i) { // 分割每个站台
            int mid = 0;
            while (i < s.size() && isdigit(s[i])) {
                mid = mid * 10 + (s[i++] - '0');
            }
            a.emplace_back(mid);
        }
        for (int i = 0; i < a.size(); ++i) { // 当前站台可以去接下来的每一个站台
            for (int j = i + 1; j < a.size(); ++j) {
                g[a[i]].emplace_back(a[j]);
            }
        }
    }

    function<int()> dijkstra = [&]() -> int { // 有点像 bfs，肯定是一条线路一条线路遍历过去的
        queue<pair<int, int>> q;
        vector<bool> memo(n + 1, true);
        q.emplace(1, 0);
        memo[1] = false;
        while (q.size()) {
            auto [u, dist] = q.front();
            if (u == n) { // 到达终点
                return dist;
            }
            q.pop();
            for (int v : g[u]) {
                if (memo[v]) {
                    memo[u] = false; // 再换乘回去肯定要多一次，所以肯定不回去
                    q.emplace(v, dist + 1);
                }
            }
        }
        return -1;
    };

    int ans = dijkstra();
    if (ans == -1) {
        cout << "NO";
    } else {
        cout << ans - 1;
    }
    return 0;
}
