import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
ab = [tuple(map(int, input().split())) for _ in range(n + 1)]
ans, now = 0, 1
ab.sort(key = lambda x : x[0] * x[1])
for a, b in ab:
    ans = max(ans, now // b)
    now *= a
print(ans)
