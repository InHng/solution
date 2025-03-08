class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans, mid = [], ""

        def dfs(i, l):
            nonlocal mid
            if i == 2 * n:
                ans.append(mid)
                return
            if l < n:
                mid += '('
                dfs(i + 1, l + 1)
                mid = mid[:-1]
            if i - l < l:
                mid += ')'
                dfs(i + 1, l)
                mid = mid[:-1]
        
        dfs(0, 0)
        return ans
