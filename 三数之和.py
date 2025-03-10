class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()
        for i, x in enumerate(nums):
            if i and x == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                if nums[left] + nums[right] == -x:
                    ans.add((nums[i], nums[left], nums[right]))
                    left += 1
                elif nums[left] + nums[right] < -x:
                    left += 1
                else:
                    right -= 1
        return list(ans)
