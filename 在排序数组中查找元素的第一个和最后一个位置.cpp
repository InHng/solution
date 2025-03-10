class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = ranges::lower_bound(nums, target) - nums.begin();
        if (left == nums.size() or nums[left] ^ target) {
            return {-1, -1};
        }
        int right = ranges::upper_bound(nums, target) - nums.begin() - 1;
        return {left, right};
    }
};
