import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

s = list(input())
n = len(s)
same, diff = 0, 0
for i in range(1, n):
    if s[i] == s[i - 1]:
        same += 1
    else:
        diff += 1
print(same * diff + 1)
