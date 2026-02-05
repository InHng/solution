#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (char c : s) {
        if (c == '(') {
            cnt += 1;
            ans = max(ans, cnt);
        } else {
            cnt -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
