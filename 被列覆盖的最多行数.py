class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        mask, suf = [0 for _ in range(15)], [0 for _ in range(15)]
        m, n = len(matrix), len(matrix[0])
        ans, numSelect = m, n - numSelect

        def dfs(i, cnt, cover):
            if cnt == numSelect:
                nonlocal ans
                ans = min(ans, cover.bit_count())
                return
            if cnt + n - i == numSelect:
                dfs(n, numSelect, cover | suf[i])
            else:
                dfs(i + 1, cnt + 1, cover | mask[i])
                dfs(i + 1, cnt, cover)
        
        for j in range(n):
            mask[j] = 0
            for i in range(m):
                mask[j] |= matrix[i][j] << i

        suf[n - 1] = mask[n - 1]
        for i in range(n - 2, -1, -1):
            suf[i] = suf[i + 1] | mask[i]
        
        dfs(0, 0, 0)
        return m - ans
