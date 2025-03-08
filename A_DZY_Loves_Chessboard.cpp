#include <bits/stdc++.h>
using namespace std;

int next_step[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

signed main() {
    int t, n, m, next_x, next_y;
    cin >> n >> m;
    vector<string> a(n);
    for (string& ai : a) {
        cin >> ai;
    }

    function<void(int, int, char)> dfs = [&](int x, int y, char c) -> void {
        a[x][y] = c;
        for (int i = 0; i < 4; ++i) {
            next_x = x + next_step[i][0];
            next_y = y + next_step[i][1];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && a[next_x][next_y] == '.') {
                dfs(next_x, next_y, c == 'B' ? 'W' : 'B');
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                dfs(i, j, 'B');
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
