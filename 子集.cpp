class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for (int num : nums) {
            vector<vector<int>> mid(ans);
            for (vector<int> m : mid) {
                m.emplace_back(num);
                ans.emplace_back(m);
            }
        }
        return ans;
    }
};
