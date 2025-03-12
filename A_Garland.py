n = int(input())  # 输入 n
p = [0] + list(map(int, input().split()))
cnt = [0, 0]  # 用于统计奇数和偶数的数量

for i in range(1, n + 1):
    cnt[i & 1] += 1  # 判断是奇数还是偶数并更新计数

# dp[i][j][k] 表示前 i 个数中有 j 个偶数且最末尾为 k (0 表示偶数，1 表示奇数) 的最小结果
INF = 0x3f3f3f3f
dp = [[[INF] * 2 for _ in range(cnt[0] + 2)] for _ in range(n + 1)]  # 初始化 dp 数组

dp[0][0][0] = dp[0][0][1] = 0  # 边界条件，前 0 个数时，偶数奇数计数都为 0

for i in range(1, n + 1):
    for j in range(min(i, cnt[0] + 1)):  # 确保 j 不超过偶数的最大数量
        for k in range(2):  # 最后一位是偶数 (0) 或奇数 (1)
            if p[i] != 0:  # 如果这个位置的数字已经固定
                if p[i] & 1:  # 如果是奇数
                    dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + (k ^ 1))
                else:  # 如果是偶数
                    dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i - 1][j][k] + (k & 1))
            else:  # 如果这个位置的数字未固定
                for l in range(2):  # l 代表选择偶数还是奇数
                    dp[i][j + 1 - l][l] = min(dp[i][j + 1 - l][l], dp[i - 1][j][k] + (k ^ l))

print(min(dp[n][cnt[0]][0], dp[n][cnt[0]][1])) 
