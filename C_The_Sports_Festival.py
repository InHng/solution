n = int(input())
s = list(map(int, input().split()))
s.sort()
dp = [[0 for _ in range(n)] for _ in range(n)]  # dp[i][j] 表示取 i 到 j 学生的最小差值

for i in range(1, n):  # 第 i + 1 天
    for j in range(n - i):  # 从 j 学生开始取 i 个人
        left, right = j, j + i
        dp[left][right] = s[right] - s[left] + min(dp[left + 1][right], dp[left][right - 1])
print(dp[0][n - 1])
