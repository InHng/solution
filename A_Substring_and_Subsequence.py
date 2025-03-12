MOD = int(1e9) + 7

s = input()
t = input()
l1, l2 = len(s), len(t)
dp = [[0] * (l2 + 1) for _ in range(l1 + 1)]

for i in range(l1):
    for j in range(l2):
        # 如果两个位置相等，那么之前位置的值也需要加过来
        dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % MOD

print(sum(dp[i + 1][l2] for i in range(l1)) % MOD)
