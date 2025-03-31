n, V = map(int, input().split())
dp = [0 for _ in range(V + 1)]
for _ in range(n):
    v, w = map(int, input().split())
    for j in range(V, v - 1, -1):
        dp[j] = max(dp[j], dp[j - v] + w)
print(max(dp))
