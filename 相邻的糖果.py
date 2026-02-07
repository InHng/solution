import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m, x = map(int, input().split())
ans, cnt = 0, 0
a = list(map(int, input().split()))
for i in range(n):
    cnt += a[i]
    if i >= m:
        cnt -= a[i - m]
    if cnt > x:
        ans += cnt - x
        a[i] -= cnt - x
        cnt = x
print(ans)
