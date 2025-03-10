class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans, left,sum = len(nums) + 1, 0, 0
        for right, num in enumerate(nums):
            sum += num
            while sum - nums[left] >= target:
                sum -= nums[left]
                left += 1
            if sum >= target:
                ans = min(ans, right - left + 1)
        return ans if ans != len(nums) + 1 else 0
