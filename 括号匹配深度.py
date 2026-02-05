import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

s = list(input())
ans, cnt = 0, 0
for c in s:
    if c == '(':
        cnt += 1
        ans = max(ans, cnt)
    else:
        cnt -= 1
print(ans)
