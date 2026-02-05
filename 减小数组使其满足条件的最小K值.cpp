class Solution {
public:
    int minimumK(vector<int>& nums) {
        int left = ceil(sqrt(nums.size())) - 1, right = *max_element(nums.begin(), nums.end()) + 1;
        while (left + 1 < right) {
            int mid = (left + right) >> 1, cnt = 0;
            for (int num : nums) {
                cnt += (num + mid - 1) / mid;
            }
            if (cnt <= (long long)mid * mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left + 1;
    }
};
