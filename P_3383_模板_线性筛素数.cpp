#include <bits/stdc++.h>
using namespace std;

#define int long long

bool memo[100000001] = {false};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (not memo[i]) {
            primes.emplace_back(i);
        }
        for (int j = 0; j < primes.size() and i * primes[j] <= n; ++j) {
            memo[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    
    while (q--) {
        int x;
        cin >> x;
        cout << primes[x - 1] << endl;
    }

    return 0;
}
