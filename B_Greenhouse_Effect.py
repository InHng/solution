n, m = map(int, input().split())
a = [None for _ in range(n + 1)]
dp = [0 for _ in range(n + 1)]
ans = 0

for i in range(1, n + 1):
    a[i] = tuple(map(float, input().split()))
    dp[i] = 1
    for j in range(1, i):
        if a[i][0] >= a[j][0]:
            dp[i] = max(dp[i], dp[j] + 1)
    ans = max(ans, dp[i])

if n == 1:
    exit(print(0))
print(n - ans)
