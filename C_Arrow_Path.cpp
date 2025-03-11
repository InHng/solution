#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(2, vector<char> (n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> memo(2, vector<bool>(n));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == 1 and y == n - 1) {
            cout << "YES" << endl;
            return;
        }
        if (memo[x][y]) {
            continue;
        }
        memo[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (~xx and xx < 2 and ~yy and yy < n) {
                yy += (g[xx][yy] == '>' ? 1 : -1);
                if (~xx and xx < 2 and ~yy and yy < n) {
                    q.emplace(xx, yy);
                }
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
