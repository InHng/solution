class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n, ans = len(words), 0
        mask = [0 for _ in range(n)]
        for i in range(n):
            for c in words[i]:
                mask[i] |= (1 << (ord(c) - ord('a')))
        for i in range(n):
            for j in range(n):
                if mask[i] & mask[j] == 0:
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans
