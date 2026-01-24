import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
g = [list(map(int, input().split())) for _ in range(n)]
dp = [[[0x3f3f3f3f for _ in range(4)] for _ in range(n)] for _ in range(1 << n)]
for i in range(n):
    dp[1 << i][i][0] = 0
for i in range(1, 1 << n):
    for j in range(n):
        if not (i >> j) & 1:
            continue
        for k in range(n):
            if j == k or not (i >> k) & 1:
                continue
            last = i - (1 << j)
            for l in range(4):
                dp[i][j][l] = min(dp[i][j][l], dp[last][k][l] + g[k][j])
            dp[i][j][1] = min(dp[i][j][1], dp[last][k][0])
            dp[i][j][2] = min(dp[i][j][2], dp[last][k][0] + g[k][j] * 2)
            dp[i][j][3] = min(dp[i][j][3], dp[last][k][1] + g[k][j] * 2)
            dp[i][j][3] = min(dp[i][j][3], dp[last][k][2])
print(min(dp[(1 << n) - 1][i][3] for i in range(n)))
