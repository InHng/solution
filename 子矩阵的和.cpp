#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
