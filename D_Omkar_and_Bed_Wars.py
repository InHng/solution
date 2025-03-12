for _ in range(int(input())):
    n = int(input())
    s = ['$'] + list(input())
    ans = 0x3f3f3f3f
    for i in range(1, 5):
        dp = [0x3f3f3f3f for _ in range(n + 1)]
        dp[0] = 0
        for j in range(2, n + 1):
            dp[j] = min(dp[j], dp[j - 2] + (s[j] != 'L') + (s[j - 1] != 'R'))
            if j >= 3:
                dp[j] = min(dp[j], dp[j - 3] + (s[j] != 'L') + (s[j - 2] != 'R'))
            if j >= 4:
                dp[j] = min(dp[j], dp[j - 4] + (s[j] != 'L') + (s[j - 1] != 'L') + (s[j - 2] != 'R') + (s[j - 3] != 'R'))
        ans = min(ans, dp[n])
        s = [s[0]] + s[2:] + [s[1]]
    print(ans)

