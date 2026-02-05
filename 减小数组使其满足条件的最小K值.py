class Solution:
    def minimumK(self, nums: List[int]) -> int:
        left, right = ceil(sqrt(len(nums))) - 1, max(nums) + 1
        while left + 1 < right:
            mid = (left + right) >> 1
            cnt = 0
            for num in nums:
                cnt += (num + mid - 1) // mid
            if cnt <= mid * mid:
                right = mid
            else:
                left = mid
        return left + 1
