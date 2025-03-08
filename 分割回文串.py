class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans, path = [], []

        def judge(s, left, right):
            while left < right:
                if s[left] != s[right]:
                    return False
                left, right = left + 1, right - 1
            return True
        
        def dfs(i):
            if i == n:
                ans.append(path.copy())
                return
            for j in range(i, n):
                if judge(s, i, j):
                    path.append(s[i:j + 1])
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return ans
