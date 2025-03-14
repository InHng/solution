class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + nums[i];
        }
        if (pre[n - 1] - pre[0] == 0) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            if (pre[i - 1] == pre[n - 1] - pre[i]) {
                return i;
            }
        }
        return -1;
    }
};
