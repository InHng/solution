#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> path;

    function<void(int)> dfs = [&](int pos) {
        for (int i = 0; i < path.size(); i++) {
            if (i and path[i] < path[i - 1]) {
                return;
            }
        }
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        for (int i = pos; i <= n; i++) {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    };

    dfs(1);
    return 0;
}
