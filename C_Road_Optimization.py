n, l, m = map(int, input().split())
d = list(map(int, input().split())) + [l]
a = list(map(int, input().split()))
dp = [[0x3f3f3f3f for _ in range(m + 1)] for _ in range(n + 1)]
dp[0][0] = 0
for i in range(1, n + 1):  # 当前位置为 i
    for j in range(m + 1):  # 此时一共删除了 j 个标志
        for k in range(i - 1, -1, -1):  # 将 k -> i 中间的标志全部删除
            last_j = j - (i - k - 1)  # 删除 k -> i 之间的所有标志之前，已删除的标志数
            if last_j >= 0:
                dp[i][j] = min(dp[i][j], dp[k][last_j] + a[k] * (d[i] - d[k]))
print(min(dp[n][i] for i in range(m + 1)))
