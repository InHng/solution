class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        all = sum(nums[1:])
        left = 0
        if left == all:
            return 0
        for i, x in enumerate(nums[1:], 1):
            left += nums[i - 1]
            all -= x
            if left == all:
                return i
        return -1
