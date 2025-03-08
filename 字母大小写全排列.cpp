class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();

        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.emplace_back(s);
                return;
            }

            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
                dfs(i + 1);
                s[i] = toupper(s[i]);
                dfs(i + 1);
            } else {
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
