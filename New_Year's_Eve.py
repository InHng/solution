import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, k = map(int, input().split())
ans = 1
if k == 1:
    exit(print(n))
while 2 * ans <= n:
    ans <<= 1
print(ans * 2 - 1)
