class Solution:
    def totalNQueens(self, n: int) -> int:
        ans = 0
        col, dig, back_dig = [0 for _ in range(n * 2 + 1)], [0 for _ in range(n * 2 + 1)], [0 for _ in range(n * 2 + 1)]
        
        def dfs(deep):
            if deep == n:
                nonlocal ans
                ans += 1
                return
            for i in range(n):
                if (not (col[i] or dig[n + deep - i] or back_dig[deep + i])):
                    col[i] = dig[n + deep - i] = back_dig[deep + i] = 1
                    dfs(deep + 1)
                    col[i] = dig[n + deep - i] = back_dig[deep + i] = 0
        
        dfs(0)
        return ans
