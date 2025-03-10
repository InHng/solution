#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (st.size() && st.top() >= a[i]) {
            st.pop();
        }
        if (st.size()) {
            cout << st.top() << " ";
        } else {
            cout << "-1" << " ";
        }
        st.push(a[i]);
    }
    return 0;
}
