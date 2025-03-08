#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}
