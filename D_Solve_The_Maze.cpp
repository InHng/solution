#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1));
    map<pair<int, int>, bool> mp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'G') {
                mp[{i, j}] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == 'B') { // 用墙把坏人四周围起来
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x and x <= n and y and y <= m) {
                        if (g[x][y] == 'G') { // 坏人可以和好人挨在一起逃离出口
                            cout << "No" << endl;
                            return;
                        } else if (g[x][y] == '.') {
                            g[x][y] = '#';
                        }
                    }
                }
            }
        }
    }
    if (g[n][m] == '#' and mp.size()) {
        cout << "No" << endl;
        return;
    }
    queue<pair<int, int>> q;
    q.emplace(n, m);
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx and xx <= n and yy and yy <= m and (g[xx][yy] == '.' or g[xx][yy] == 'G')) {
                q.emplace(xx, yy);
                if (g[xx][yy] == 'G') {
                    mp[{xx, yy}] = false;
                }
                g[xx][yy] = '#';
            }
        }
    }
    for (auto [_, x] : mp) {
        if (x) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
