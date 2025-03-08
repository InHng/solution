class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        function<bool(string, int, int)> judge = [&](string s, int left, int right) -> bool {
            while (left < right) {
                if (s[left++] != s[right--]) {
                    return false;
                }
            }
            return true;
        };

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (judge(s, i, j)) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};
