#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    int g[n + 1][n + 1];
    memset(g, INF, sizeof(g));
    for (int i = 0; i <= n; ++i) {
        g[i][i] = 0;
    }

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    // floyd;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while (k--) {
        int x, y;
        cin >> x >> y;
        if (g[x][y] >= INF) {
            cout << "impossible\n";
        } else {
            cout << g[x][y] << endl;
        }
    }
    return 0;
}
