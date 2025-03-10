class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        nums.sort(reverse = True)
        cnt = nums.copy()
        for i in range(1, n):
            cnt[i] += cnt[i - 1]
        for i in range(n):
            if cnt[n - 1] - cnt[i] > nums[i]:
                ans = max(ans, cnt[n - 1] - cnt[i] + nums[i])
        return ans
