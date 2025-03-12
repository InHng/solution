n, m, x, y = map(int, input().split())
g = [" " + input() for _ in range(n)]

if m < x or (m > y and m < 2 * x):
    exit(print(0))

a = [0 for _ in range(m + 1)]   # 每一列的黑色方块数量前缀和
for j in range(1, m + 1):
    for i in range(n):
        a[j] += (g[i][j] == '#')
    a[j] += a[j - 1]

# dp[i][0] 表示从第一列到第 i 列，最后一列是 '.' 的重绘个数
# dp[i][1] 表示从第一列到第 i 列，最后一列是 '#' 的重绘个数
dp = [[0x3f3f3f3f, 0x3f3f3f3f] * 2 for _ in range(m + 1)]

for i in range(x, min(m, y) + 1):
    dp[i][0] = i * n - a[i]
    dp[i][1] = a[i]

for i in range(2 * x, m + 1):
    for j in range(x, y + 1):
        l = i - j
        if l < x:
            break
        dp[i][0] = min(dp[i][0], dp[l][1] + (j * n - (a[i] - a[l])))
        dp[i][1] = min(dp[i][1], dp[l][0] + (a[i] - a[l]))

print(min(dp[m][0], dp[m][1]))
