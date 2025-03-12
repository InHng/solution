MOD = int(1e8)

n1, n2, k1, k2 = map(int, input().split())
    
# dp[i][j][k] 表示当前使用了 i 个步兵和 j 个骑兵，且队伍末尾为 k (0 表示步兵，1 表示骑兵)
dp = [[[0 for _ in range(2)] for _ in range(n2 + 1)] for _ in range(n1 + 1)]

for i in range(min(n1, k1) + 1):  # 在满足条件的情况下全部排步兵
    dp[i][0][0] = 1
for i in range(min(n2, k2) + 1):  # 在满足条件的情况下全部排骑兵
    dp[0][i][1] = 1

for i in range(1, n1 + 1):
    for j in range(1, n2 + 1):
        for k in range(1, min(i, k1) + 1):  # 末尾有 k 个连续的步兵
            dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD
        for k in range(1, min(j, k2) + 1):  # 末尾有 k 个连续的骑兵
            dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD

print((dp[n1][n2][0] + dp[n1][n2][1]) % MOD)
