dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

n, m = map(int, input().split())
g = [list(input()) for _ in range(n)]

for i in range(n):
    for j in range(m):
        if g[i][j] == '.':
            g[i][j] = 'B'
            q = [(i, j)]
            while q:
                x, y = q.pop()
                for k in range(4):
                    if 0 <= x + dx[k] < n and 0 <= y + dy[k] < m and g[x + dx[k]][y + dy[k]] == '.':
                        g[x + dx[k]][y + dy[k]] = ('B' if g[x][y] == 'W' else 'W')
                        q.append((x + dx[k], y + dy[k]))

for i in range(n):
    print("".join(g[i]))
