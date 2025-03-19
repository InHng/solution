#include <bits/stdc++.h>
using namespace std;

#define ing long long

void kmp(string main, string pattern) { // 返回子串位置
    int n = main.size(), m = pattern.size();
    string s = pattern + " " + main;
    vector<int> pi(n + m + 1);
    for (int i = 1; i <= n + m; ++i) {
        int len = pi[i - 1];
        while (len and s[i] != s[len]) {
            len = pi[len - 1];
        }
        if (s[i] == s[len]) {
            pi[i] = len + 1;
            if (pi[i] == m) {
                cout << i - m * 2 << " ";
            }
        }
    }
}

signed main() {
    int n, m;
    string P, S;
    cin >> n >> P >> m >> S;
    kmp(S, P);
}
