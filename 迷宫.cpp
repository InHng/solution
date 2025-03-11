#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INT_MAX 0x3f3f3f3f
#define INT_MIN -0x3f3f3f3f

int t, H, W, start_x, start_y;

struct node {
    int x, y, key, step;
};

int next_step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    cin >> H >> W;
    vector a(H, vector<char>(W));
    bool memo[H][W][2];
    memset(memo, false, sizeof(memo));
    queue<node> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
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
            if (a[x][y] == 'E') {
                return step;
            }
            for (int i = 0; i < 4; ++i) {
                int next_x = x + next_step[i][0], next_y = y + next_step[i][1], next_key = key;
                if (a[next_x][next_y] == 'K') {
                    next_key = 1;
                }
                if (memo[next_x][next_y][key] || a[next_x][next_y] == 'W' || (a[next_x][next_y] == 'D' && !key)) {
                    continue;
                }
                memo[next_x][next_y][key] = 1;
                q.push((node){next_x, next_y, next_key, step + 1});
            }
        }
        return -1;
    };
    
    cout << bfs(start_x, start_y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    while (t--) solve();
    return 0;
}
