n, m, c0, d0 = map(int, input().split())
a, b, c, d = [], [], [], []
for _ in range(m):
    ai, bi, ci, di = map(int, input().split())
    a.append(ai)
    b.append(bi)
    c.append(ci)
    d.append(di)

dp = [0 for _ in range(n + 1)]  # dp[i] 表示用掉 i 克面团最多可以获得多少钱

for i in range(n + 1):  # 全做不带馅的面包
    dp[i] = (i // c0) * d0

for i in range(m):  # 遍历每种面包的制作
    for _ in range(a[i] // b[i]):   # 最多可以做 a[i] / b[i] 个
        for k in range(n, c[i] - 1, -1):  # 最少需要 c[i] 克面团
            dp[k] = max(dp[k], dp[k - c[i]] + d[i])

print(dp[n])
