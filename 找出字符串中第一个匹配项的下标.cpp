class Solution {
public:
    int strStr(string main, string pattern) {
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
                    return i - m * 2;
                }
            }
        }
        return -1; // 没找到
    }
};
