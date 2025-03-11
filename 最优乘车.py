import sys
input = lambda: sys.stdin.readline().strip()

m, n = map(int, input().split())
g = [[0x3f3f3f3f for _ in range(501)] for _ in range(501)]
for _ in range(m):
    line = list(map(int, input().split()))
    for i, x in enumerate(line):
        for j in range(i + 1, len(line)):
            g[x][line[j]] = 1

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])
if g[1][n] >= 0x3f3f3f3f:
    print("NO")
else:
    print(g[1][n] - 1)
