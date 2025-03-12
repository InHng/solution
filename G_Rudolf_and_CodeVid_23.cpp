#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
const int INF = 0x3f3f3f3f;

// to_ulong: bitset -> unsigned long
// to_ullong: bitset -> unsigned long long

void solve() {
    int n, m, s;
    bitset<10> temp;
    cin >> n >> m >> temp;
    s = (int)temp.to_ullong(); // bitset -> unsigned long long
    vector<pair<int, pair<int, int>>> medicines(m); // 三个参数分别是需要服用的天数，消除的症状，出现的新症状
    vector<int> dist(1 << n, INF); // 一共有 1 << n 种症状
    dist[s] = 0; // 初始状态需要 0 天
    for (pair<int, pair<int, int>> &mi : medicines) {
        cin >> mi.ff >> temp;
        mi.ss.ff = (int)temp.to_ullong() ^ ((1 << n) - 1); // 注意这里将 0 和 1 的含义交换
        cin >> temp;
        mi.ss.ss = (int)temp.to_ullong();
    }

    function<int()> dijkstra = [&]() -> int {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, s);
        while (q.size()) {
            // 当前所要的天数 和 从哪个状态转换
            auto [day, from] = q.top();
            q.pop();
            for (pair<int, pair<int, int>> medicine : medicines) {
                // to 表示将要去的状态
                int to = from & medicine.ss.ff; // 消除旧症状
                to |= medicine.ss.ss; // 出现新症状
                if (dist[to] > day + medicine.ff) {
                    dist[to] = day + medicine.ff;
                    q.emplace(dist[to], to);
                }
            }
        }
        return (dist[0] == INF) ? -1 : dist[0];
    };
    
    cout << dijkstra() << endl;
}

signed main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
