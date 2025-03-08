#include <bits/stdc++.h>
using namespace std;

int steps[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector all(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> all[i][j];
        }
    }
    
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0 || i >= n || j < 0 || j >= m || all[i][j] == 0) {
            return 0;
        }
        int sum = all[i][j];
        all[i][j] = 0;
        for (auto step : steps) {
            sum += dfs(i + step[0], j + step[1]);
        }
        return sum;
    };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
