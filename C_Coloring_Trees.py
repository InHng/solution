n, m, k = map(int, input().split())

# dp[i][j][k] 表示前 i 棵树的最后一棵树涂第 j 种颜色，并且涂成 k 个相同连续段的最小花费
dp = [[[0x3f3f3f3f for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(n + 1)]
dp[0][0][0] = 0

c = [0] + list(map(int, input().split()))

p = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
for i in range(1, n + 1):
    costs = list(map(int, input().split()))
    for j in range(1, m + 1):
        p[i][j] = 0 if c[i] else costs[j - 1]

for i in range(n):
    for j in range(m + 1):
        for t in range(i + 1):
            if c[i + 1]:  # 如果下一个位置已经涂了颜色
                dp[i + 1][c[i + 1]][t + (c[i + 1] != j)] = min(
                    dp[i + 1][c[i + 1]][t + (c[i + 1] != j)], dp[i][j][t]
                )
            else:
                for color in range(1, m + 1):
                    dp[i + 1][color][t + (color != j)] = min(
                        dp[i + 1][color][t + (color != j)], dp[i][j][t] + p[i + 1][color]
                    )

ans = 0x3f3f3f3f
for i in range(1, m + 1):
    ans = min(ans, dp[n][i][k])

print(-1 if ans == 0x3f3f3f3f else ans)
