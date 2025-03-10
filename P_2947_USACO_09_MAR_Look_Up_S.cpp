#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> ans(n), h(n);
    for (int &hi : h) {
        cin >> hi;
    }
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; --i) {
        while (s.size() and s.top().ff <= h[i]) {
            s.pop();
        }
        if (s.size()) {
            ans[i] = s.top().ss;
        }
        s.emplace(h[i], i + 1);
    }
    for (int x : ans) {
        cout << x << endl;
    }
    return 0;
}
