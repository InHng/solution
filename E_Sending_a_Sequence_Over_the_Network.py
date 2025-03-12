for _ in range(int(input())):
    n = int(input())
    dp = [0 for _ in range(n + 1)]
    dp[0] = 1
    b = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        if i + b[i] <= n and dp[i - 1]:
            dp[i + b[i]] = 1
        if i - b[i] > 0 and dp[i - b[i] - 1]:
            dp[i] = 1
    print("YES" if dp[n] else "NO")
