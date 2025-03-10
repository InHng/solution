class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long ans = -1;
        sort(nums.begin(), nums.end(), greater());
        vector<long long> cnt(n);
        for (int i = 0; i < n; ++i) {
            cnt[i] = nums[i];
        }
        for (int i = 1; i < n; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[n - 1] - cnt[i] > nums[i]) {
                ans = max(ans, (long long)cnt[n - 1] - (long long)cnt[i] + (long long)nums[i]);
            }
        }
        return ans;
    }
};
