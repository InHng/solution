#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> memo(1001, -1);

int f(int x) {
    if (x == 1) {
        return 1;
    }
    if (memo[x] != -1) {
        return memo[x];
    }
    int ans = 1;
    for (int i = 1; i <= x / 2; ++i) {
        ans += f(i);
    }
    return memo[x] = ans;
}

signed main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}
