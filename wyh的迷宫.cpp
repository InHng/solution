#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m, sx, sy, tx, ty;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> dis(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for(int j = 0; j < m; j++) {
            if (g[i][j] == 's') {
                sx = i;
                sy = j;
            }
            if (g[i][j] == 't') {
                tx = i;
                ty = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
    
    while (q.size()){
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 and xx < n and yy >= 0 and y < m and g[xx][yy] != 'x' and dis[xx][yy] == -1) {
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    cout << (dis[tx][ty] == -1 ? "NO" : "YES") << endl;
}

int main(){
    int Test; cin >> Test; while(Test--)
    solve();
    return 0;
}
