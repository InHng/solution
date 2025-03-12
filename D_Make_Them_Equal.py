d = [0x3f3f3f3f for _ in range(1001)]
d[1] = 0
for i in range(1, 1001):
    for j in range(1, i + 1):
        x = i + i // j
        if x <= 1000:
            d[x] = min(d[x], d[i] + 1)
for _ in range(int(input())):
    n, k = map(int, input().split())
    k = min(k, 12 * n)
    a, dp = [1 for _ in range(n)], [0 for _ in range(k + 1)]
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    for i in range(n):
        for j in range(k, d[b[i]] - 1, -1):
            dp[j] = max(dp[j], dp[j - d[b[i]]] + c[i])
    print(dp[k])
