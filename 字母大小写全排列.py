class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        s = list(s)
        n = len(s)

        def dfs(i):
            if i == n:
                ans.append("".join(s))
                return
            if s[i].isalpha():
                s[i] = s[i].lower()
                dfs(i + 1)
                s[i] = s[i].upper()
                dfs(i + 1)
            else:
                dfs(i + 1)
        
        dfs(0)
        return ans
