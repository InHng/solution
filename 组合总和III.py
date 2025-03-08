class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        mid = []
        def dfs(i, x : int) -> None:
            d = k - len(mid)
            if x < 0 or x > (i * 2 - d + 1) * d // 2: # x > (i + (i - d + 1)) * d // 2 无论怎样都达不到目标值
                return 
            if d == 0:
                ans.append(mid.copy())
                return
            if i > d:
                dfs(i - 1, x)
            mid.append(i)
            dfs(i - 1, x - i)
            mid.pop()
        dfs(9, n)
        return ans
