class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int ai : nums) {
            ans ^= ai;
        }
        return ans;
    }
};
