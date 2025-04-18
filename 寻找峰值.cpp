class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // 先判断边界条件
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 2] < nums[n - 1]) return n - 1;

        int left = 1, right = n - 2;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
