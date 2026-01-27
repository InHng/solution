import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, k, x = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse = True)
a = a[-k:]
cnt = 0
for i, ai in enumerate(a):
    cnt += ai
    if cnt >= x:
        exit(print(i + 1 + n - k))
print(-1)
