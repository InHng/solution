class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i and nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                } else if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
