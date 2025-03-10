n, m, q = map(int, input().split())
g = [[0 for _ in range(m + 2)]] + [[0] + list(map(int, input().split())) for _ in range(n)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1]

for _ in range(q):
    x1, y1, x2, y2 = map(int, input().split())
    print(g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1])
