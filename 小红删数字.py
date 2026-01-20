import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7

n = int(input())
a = list(map(int, input().split()))
dp = [0 for _ in range(10)]
if n == 1:
    if a[0] < 10:
        dp[a[0]] = 1
    print(*dp)
    exit()
dp[a[-1] % 10] = 1
for i in range(n - 2, -1, -1):
    next_dp = [0 for _ in range(10)]
    a[i] %= 10
    for j in range(10):
        next_add, next_mul = (a[i] + j) % 10, (a[i] * j) % 10
        next_dp[next_add] = (next_dp[next_add] + dp[j]) % mod
        next_dp[next_mul] = (next_dp[next_mul] + dp[j]) % mod
    dp = next_dp[:]
print(*dp)
