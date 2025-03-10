class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> cnt;
        int ans = 0, left = 0, right = 0;
        while (right < s.size()) {
            ++cnt[s[right]];
            while (cnt[s[right]] > 1) {
                --cnt[s[left]];
                left++;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};
