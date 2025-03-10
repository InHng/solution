#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    while (cin >> n >> m, n or m) { // 以 0 0结尾
        int cnt = 0;
        bool flag = true;
        vector<bool> memo(n);
        vector<int> g[n], in(n);

        function<void(int, vector<int>[])> topsort = [&](int i, vector<int> g[]) {
            queue<int> q;
            vector<int> IN(in);
            for (int i = 0; i < n; ++i) {
                if (not IN[i]) {
                    q.emplace(i);
                }
            }
            string ans = "";
            bool unique = true;
            while (q.size()) {
                if (q.size() > 1) {
                    unique = false;
                }
                int u = q.front();
                q.pop();
                ans += 'A' + u;
                for (int v : g[u]) {
                    if (--IN[v] == 0) {
                        q.emplace(v);
                    }
                }
            }
            if (ans.size() < cnt) {
                flag = false;
                cout << "Inconsistency found after " << i << " relations." << endl;
            } else if (ans.size() == n and unique) {
                flag = false;
                cout << "Sorted sequence determined after " << i << " relations: " << ans << "." << endl;
            }
        };

        for (int i = 1; i <= m; ++i) {
            string s;
            cin >> s;
            if (not flag) {
                continue;
            }
            int a = s[0] - 'A', b = s[2] - 'A';
            if (not memo[a]) {
                memo[a] = true;
                ++cnt;
            }
            if (not memo[b]) {
                memo[b] = true;
                ++cnt;
            }
            if (a == b) {
                flag = false;
                cout << "Inconsistency found after " << i << " relations." << endl;
                continue;
            }
            g[a].emplace_back(b);
            ++in[b];
            topsort(i, g);
        }
        if (flag) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }
    
    return 0;
}
