#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int INF = 0x3f3f3f3f;

signed main() {
    cout << fixed << setprecision(6);
    int n;
    double ans1 = 0, ans2 = INF;
    cin >> n;
    vector<double> step(n + 1, 0); // 点 i 对于其他点最远的距离
    vector<pair<int, int>> idx(n + 1);
    vector g(n + 1, vector<double>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        cin >> idx[i].ff >> idx[i].ss;
    }

    // 求路径
    function<double(pair<int, int>, pair<int, int>)> len = [&](pair<int, int> a, pair<int, int> b) -> double {
        auto [x1, y1] = a;
        auto [x2, y2] = b;
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    
    for (int i = 1; i <= n; ++i) {
        g[i][i] = 0;
        string s;
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= n; ++j) {
            if (s[j] - '0') {
                g[i][j] = len(idx[i], idx[j]);
            }
        }
    }

    // Floyd 求最短路
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    // 不建新路
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] != INF) { // 求出离当前位置最远的点的距离
                step[i] = max(step[i], g[i][j]);
            }
            ans1 = max(ans1, step[i]);
        }
    }
    // 建造新路
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == INF) { // 原本没有路，现在临时修一条
                ans2 = min(ans2, step[i] + len(idx[i], idx[j]) + step[j]);
            }
        }
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}
