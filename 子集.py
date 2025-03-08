class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        n = len(nums)

        def dfs(i):
            ans.append(path.copy())
            for j in range(i, n):
                path.append(nums[j])
                dfs(j + 1)
                path.pop()
                
        dfs(0)
        return ans
