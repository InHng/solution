class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = Counter()
        left, ans = 0, 0
        for right, c in enumerate(s):
            mp[c] += 1
            while mp[c] > 1:
                mp[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans
