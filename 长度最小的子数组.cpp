class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int sum = 0;
        int ans = n + 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target)
                ans = min(ans, right - left + 1);
        }
        return ans == n + 1 ? 0 : ans;
    }
};
