class Solution:
    def strStr(self, main: str, pattern: str) -> int:
        n, m = len(main), len(pattern)
        s = pattern + " " + main
        pi = [0 for _ in range(n + m + 1)]
        for i in range(1, n + m + 1):
            l = pi[i - 1]
            while l and s[i] != s[l]:
                l = pi[l - 1]
            if s[i] == s[l]:
                pi[i] = l + 1
                if pi[i] == m:
                    return i - m * 2
        return -1
