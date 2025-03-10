#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ff first 
#define ss second 

signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }
    sort(a.begin(), a.end());
    int r = a[0].ss, ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].ff > r) {
            ans++;
        }
        r = max(r, a[i].ss);
    }
    cout << ans << endl;
    return 0;
}
