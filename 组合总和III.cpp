// 枚举下一个数选哪个
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> mid;

        function<void(int, int)> dfs = [&](int i, int x) -> void {
            int d = k - mid.size(); // 还要选 d 个数
            if (x < 0 || x > (i * 2 - d + 1) * d / 2) { // 剪枝
                return;
            }
            if (d == 0) { // 判断边界条件
                ans.emplace_back(mid);
                return;
            }
            for (int j = i; j >= d; --j) {
                mid.emplace_back(j);
                dfs(j - 1, x - j);
                mid.pop_back();
            }
        };

        dfs(9, n);
        return ans;
    }
};
