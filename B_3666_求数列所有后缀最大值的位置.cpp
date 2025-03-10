#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int unsigned long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (s.size() and a[i] >= a[s.top()]) {
            ans ^= s.top();
            s.pop();
        }
        ans ^= i;
        s.emplace(i);
        cout << ans << endl;
    }
    return 0;
}
