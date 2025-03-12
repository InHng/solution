mod = 1000000007

t, k = map(int, input().split())
dp, pre = [0 for _ in range(100005)], [0 for _ in range(100005)]
for i in range(1, k + 1):
    dp[i] += 1
    pre[i] = pre[i - 1] + dp[i]
dp[k] += 1
pre[k] += 1
for i in range(k + 1, 100005):
    dp[i] = (dp[i - 1] + dp[i - k]) % mod
    pre[i] = (pre[i - 1] + dp[i]) % mod
for _ in range(t):
    a, b = map(int, input().split())
    print((pre[b] - pre[a - 1] + mod) % mod)
