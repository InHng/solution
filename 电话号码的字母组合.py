class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        mp = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        if digits == "":
            return []
        
        def dfs(i, s):
            if i == n:
                ans.append("".join(s))
                return
            for c in list(mp[int(digits[i])]):
                s[i] = c
                dfs(i + 1, s)
        
        dfs(0, ['0' for _ in range(n)])
        return ans
