class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        left, right, ans = 0, n - 1, 0
        while left <= right:
            ans = max(ans, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ans
