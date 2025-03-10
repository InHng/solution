#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> h(n), v(n), ans(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> v[i];
        while (s.size() and h[s.top()] < h[i]) {
            ans[i] += v[s.top()];
            s.pop();
        }
        if (s.size()) {
            ans[s.top()] += v[i];
        }
        s.emplace(i);
    }
    cout << *ranges::max_element(ans) << endl;
    return 0;
}
