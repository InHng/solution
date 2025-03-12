import sys
input = lambda: sys.stdin.readline().strip()

n, m, t = map(int, input().split())
g = [[0xffffffff for _ in range(n + 1)] for _ in range(n + 1)]
for i in range(n + 1):
    g[i][i] = 0

for _ in range(m):
    x, y, z = map(int, input().split())
    g[x][y] = min(g[x][y], z)

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

for _ in range(t):
    x, y = map(int, input().split())
    if g[x][y] >= 0x3f3f3f3f:
        print("impossible")
    else:
        print(g[x][y])
