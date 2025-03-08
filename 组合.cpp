class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> mid;

        function<void(int)> dfs = [&](int i) -> void {
            if ((int)mid.size() == k) {
                ans.emplace_back(mid);
                return;
            }
            for (int j = i; j >= k - mid.size(); --j) {
                mid.emplace_back(j);
                dfs(j - 1);
                mid.pop_back();
            }
        };
        
        dfs(n);
        return ans;
    }
};
