#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> st(n + 1),path;

    function<void()> dfs = [&]() {
        if (path.size() == n) {
            for (int pi : path) {
                cout << pi << " ";
            }
            cout << endl;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (not st[i]) {
                st[i] = 1;
                path.emplace_back(i);
                dfs();
                path.pop_back();
                st[i] = 0;
            }
        }
    };

    dfs();
    return 0;
}
