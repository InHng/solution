m, n = map(int, input().split())
dp = [0 for _ in range(m + 1)]
for _ in range(n):
    p, t = map(int, input().split())
    for i in range(t, m + 1):
        dp[i] = max(dp[i], dp[i - t] + p)
print(max(dp))
