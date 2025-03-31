T, m = map(int, input().split())
dp = [0 for _ in range(T + 1)]
for _ in range(m):
    t, w = map(int, input().split())
    for i in range(T, t - 1, -1):
        dp[i] = max(dp[i], dp[i - t] + w)
print(max(dp))
