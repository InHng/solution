n = int(input())
X = list(map(int, input().split()))
dp = [0x3f3f3f3f for _ in range(n + 1)]
best = [0x3f3f3f3f for _ in range(n + 1)]
dp[0] = 0
for i, x in enumerate(X, 1):
    dp[i] = best[x] + 1
    best[x] = min(best[x], dp[i - 1])
print(-1 if dp[n] > n else dp[n])
