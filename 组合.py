class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, mid = [], []
        def dfs(i):
            if len(mid) == k:
                ans.append(mid.copy())
                return
            
            if i > k - len(mid):
                dfs(i - 1)
            mid.append(i)
            dfs(i - 1)
            mid.pop()
        dfs(n)
        return ans
