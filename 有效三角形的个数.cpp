class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
