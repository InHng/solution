class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if (digits == "") {
            return {};
        }
        function<void(int, string)> dfs = [&](int i, string s) {
            if (i == n) {
                ans.emplace_back(s);
                return;
            }
            for (char c : mp[digits[i] - '0']) {
                s[i] = c;
                dfs(i + 1, s);
            }
        };
        dfs(0, string(n, '0'));
        return ans;
    }
};
