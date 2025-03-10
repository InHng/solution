class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        # 判断边界条件
        if n == 1 or nums[0] > nums[1]:
            return 0
        if nums[n - 1] > nums[n - 2]:
            return n - 1
        
        left, right = 1, n - 2
        while left < right:
            mid = (left + right) // 2
            if nums[mid - 1] < nums[mid] and nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid - 1] < nums[mid] and nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                right = mid
        return left
