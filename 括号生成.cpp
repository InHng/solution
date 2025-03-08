class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string mid;

        function<void(int, int)> dfs = [&](int i, int l) -> void {
            if (i == 2 * n) {
                ans.emplace_back(mid);
                return;
            }

            if (l < n) { // 如果还可以添加左括号
                mid += '(';
                dfs(i + 1, l + 1);
                mid.pop_back();
            }
            if (i - l < l) { // 如果右括号的数量比左括号的数量小
                mid += ')';
                dfs(i + 1, l);
                mid.pop_back();
            }
        };

        dfs(0, 0);
        return ans;
    }
};
