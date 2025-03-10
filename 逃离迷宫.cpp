#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node {
    int x, y, key, step;
};

int next_step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    int n, m, start_x, start_y;
    cin >> n >> m;
    vector a(n + 2, vector<char>(m + 2));
    bool memo[n + 2][m + 2][2];
    memset(memo, false, sizeof(memo));
    // 地图四周建墙
    for (int i = 0; i < n + 2; ++i) {
        a[i][0] = a[i][m + 1] = '#';
    }
    for (int i = 0; i < m + 2; ++i) {
        a[0][i] = a[n + 1][i] = '#';
    }
    queue<node> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'P') {
                start_x = i, start_y = j;
            }
        }
    }

    function<int(int, int)> bfs = [&](int x, int y) -> int {
        memo[x][y][0] = 1;
        q.push((node){start_x, start_y, 0, 0});
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            int x = now.x, y = now.y, key = now.key, step = now.step;
            if (a[x][y] == 'E' && key == 1) {
                return step;
            }
            for (int i = 0; i < 4; ++i) {
                int next_x = x + next_step[i][0], next_y = y + next_step[i][1], next_key = key;
                if (a[next_x][next_y] == 'K') {
                    next_key = 1;
                }
                if (memo[next_x][next_y][key] || a[next_x][next_y] == '#' || (a[next_x][next_y] == 'E' && !key)) {
                    continue;
                }
                memo[next_x][next_y][key] = true;
                q.push((node){next_x, next_y, next_key, step + 1});
            }
        }
        return -1;
    };
    int x = bfs(start_x, start_y);
    if (x == -1) {
        cout << "No solution\n";
    } else {
        cout << x << endl;
    }
}

signed main() {
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
