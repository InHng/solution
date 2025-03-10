class Solution:
    def lower_bound(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 0:
            return [-1, -1]
        l = self.lower_bound(nums, target)
        if l > n - 1 or nums[l] != target:
            return [-1, -1]
        r = self.lower_bound(nums, target + 1) - 1
        return [l, r]
