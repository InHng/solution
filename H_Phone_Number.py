s = list(input())
n, ans = len(s), 0
if n == 1:
    exit(print(9))

dp = [[0 for _ in range(10)] for _ in range(n)]
a = [int(c) for c in s]
for i in range(10):
    dp[0][i] = 1
for i in range(n - 1):
    for j in range(10):
        dp[i + 1][(j + a[i + 1]) // 2] += dp[i][j]
        if (j + a[i + 1]) // 2 != (j + a[i + 1] + 1) // 2:
            dp[i + 1][(j + a[i + 1] + 1) // 2] += dp[i][j]
ans += sum(dp[-1])
for i in range(1, n):
    if abs(a[i] - a[i - 1]) > 1:
        break
    elif i == n - 1:
        ans -= 1
print(ans)
