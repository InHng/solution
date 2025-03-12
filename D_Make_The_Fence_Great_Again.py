for _ in range(int(input())):
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(x)
        b.append(y)

    # dp[i][j] 表示第 i 个位置增加 j 的消费
    dp = [[0x3f3f3f3f3f3f3f3f for _ in range(3)] for _ in range(n)]
    dp[0][0] = 0
    dp[0][1] = b[0]
    dp[0][2] = b[0] * 2

    for i in range(1, n):
        for j in range(3):  # 第 i 个位置的数字增加 j
            for k in range(3):  # 第 i - 1 个位置的数字增加 k
                if a[i - 1] + k != a[i] + j:  # 第 i - 1 个位置的数字增加 k
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j)

    print(min(dp[n - 1]))
