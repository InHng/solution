n, V = map(int, input().split())
dp = [0 for _ in range(V + 1)]
for _ in range(n):
    v, w = map(int, input().split())
    for i in range(v, V + 1):
        dp[i] = max(dp[i], dp[i - v] + w)
print(max(dp))
