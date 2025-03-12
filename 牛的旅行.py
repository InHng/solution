from math import sqrt
import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
step = [0 for _ in range(n + 1)]
ans1, ans2 = 0, 0x3f3f3f3f
idx, g = [()], [[0x3f3f3f3f for _ in range(n + 1)] for _ in range(n + 1)]
for _ in range(n):
    x, y = map(int, input().split())
    idx.append((x, y))

def long(a, b):
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2))

for i in range(1, n + 1):
    g[i][i] = 0
    s = " " + input()
    for j in range(1, n + 1):
        if s[j] != '0':
            g[i][j] = long(idx[i], idx[j])

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if g[i][j] != 0x3f3f3f3f:
            step[i] = max(step[i], g[i][j])
        ans1 = max(ans1, step[i])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if g[i][j] == 0x3f3f3f3f:
            ans2 = min(ans2, step[i] + long(idx[i], idx[j]) + step[j])

print(f"{max(ans1, ans2):.6f}")

